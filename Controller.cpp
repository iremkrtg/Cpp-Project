#include "Controller.h"
#include "InvalidArgumentException.h"
#include "ItemNotFoundException.h"
#include "invaliddayexception.h"

#include <string>
#include <QFile>
#include <QJsonDocument>
#include <QByteArray>
#include <QIODevice>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <string>
#include <QtDebug>
#include <QDir>

using namespace std;

Controller::Controller()
{
	repo = nullptr;
	list = nullptr;
}

Controller::Controller(Repository* repo1, Repository* list1, stack<Operation> undo1, stack<Operation> redo1)
{
	this->repo = repo1;
    this->list = list1;
    this->undo = undo1;
    this->redo = redo1;

}

Controller::~Controller()
{
}

void Controller::loadPerformance(){

    Performance* p = new Performance("AFROJACK", (char*)"Netherlands", 1, (char*)"Main", (char*)"https://afrojack.com/");
	repo->add(p);

	p = new Performance((char*)"ALESSO", (char*)"Sweden", 1, (char*)"Main", (char*)"https://www.youtube.com/channel/UC05i95k-w8CvrtZ-yGTob7A");
	repo->add(p);
	p = new Performance((char*)"DAVID GUETTA", (char*)"France", 1, (char*)"Main", (char*)"https://www.davidguetta.com/");
	repo->add(p);
	p = new Performance((char*)"IGGY AZALEA", (char*)"Australia", 1, (char*)"Main", (char*)"https://iggyazalea.com/");
	repo->add(p);
	p = new Performance((char*)"PUSSYCAT DOLLS", (char*)"USA", 1, (char*)"Main", (char*)"https://www.pcdmusic.com/");
	repo->add(p);
	p = new Performance((char*)"CIREZ D", (char*)"Sweden", 1, (char*)"Techno", (char*)"https://www.youtube.com/watch?v=vpPruqqfWQk");
	repo->add(p);
	p = new Performance((char*)"TALE OF US", (char*)"Italy", 1, (char*)"Techno", (char*)"https://soundcloud.com/taleofus");
	repo->add(p);
	p = new Performance((char*)"BORGORE", (char*)"Israel", 1, (char*)"HIP-HOP - TRAP - DRUM&BASS", (char*)"https://www.youtube.com/user/Borgore");
	repo->add(p);
	p = new Performance((char*)"NETSKY", (char*)"Belgium", 1, (char*)"HIP-HOP - TRAP - DRUM&BASS", (char*)"http://www.netskymusic.com/");
	repo->add(p);
	p = new Performance((char*)"STEVE AOKI", (char*)"USA", 1, (char*)"Main", (char*)"https://www.steveaoki.com/");
	repo->add(p);

}




Repository* Controller::getRepo()
{
	return repo;
}

Repository* Controller::getList()
{
	return list;
}

bool Controller::addPerformance(string artist, string country, int day, string stage, string link)
{
	if (repo->findPerformance(artist) != -1)
        return false;
    else {
        if(artist == "")
            throw InvalidArgumentException("You must introduce the artist's name.\n");
        if(day < 1 || day > 3)
            throw InvalidDayException("The day must be an integer between 1 and 3. \n");
		Performance* p = new Performance(artist, country, day, stage, link);
		repo->add(p);
        Operation op = Operation(ADD, p);
        undo.push(op);
		return true;
	}
}

void Controller::removePerformance(string artist)
{
	if (repo->findPerformance(artist) == -1) {
        throw ItemNotFoundException("Item not found.\n");
	}
	else
    {   if(artist == "")
            throw InvalidArgumentException("You must introduce the artist's name.\n");
		int index = repo->findPerformance(artist);
        Performance* p = repo->getElems()[index];
		repo->remove(repo->getElems()[index]);
        Operation op = Operation(REMOVE, p);
        undo.push(op);

	}
}

void Controller::updatePerformance(string givenArtist, string artist, string country, int day, string stage, string link)
{	
	
	if (repo->findPerformance(givenArtist) == -1)
        throw ItemNotFoundException("Item not found.");
	else {
        if(artist == "")
            throw InvalidArgumentException("You must introduce the artist's name.\n");
        if(day < 1 || day > 3)
            throw InvalidDayException("The day must be an integer between 1 and 3. \n");
		Performance* p = new Performance(artist, country, day, stage, link);
        int index = repo->findPerformance(givenArtist);
        Performance* p_old = repo->getElems()[index];
		repo->update(givenArtist, p);
        Operation op = Operation(UPDATE, p);

	}

}

void Controller::displayPerformance()
{
	if (repo->getLength() > 0)
		for (int i = 0; i < repo->getLength(); i++)
			std::cout << repo->getElems()[i]->getArtist() << " - " << repo->getElems()[i]->getCountry() << " - " << repo->getElems()[i]->getDay() << " - " << repo->getElems()[i]->getStage() << " - " << repo->getElems()[i]->getLink() << " \n ";
	
};

void Controller::displayList()
{
	for (int i = 0; i < list->getLength() - 1; i++)
		std::cout << list->getElems()[i]->getArtist() << "\n";
}


void Controller::displayPerfStage(string stage)
{
    if (stage == "")
		displayPerformance();
	else
		for (int i = 0; i < repo->getLength(); i++)
            if (stage == repo->getElems()[i]->getStage())
				std::cout << repo->getElems()[i]->toString() << "/n";
}

bool Controller::removeList(string artist)
{
	if (list->findPerformance(artist) == -1)
		return false;
	else {
        int index = list->findPerformance(artist);
        Performance* p = list->getElems()[index];
        Operation op = Operation(REMOVE_LIST, p);
        list->remove(p);
        undo.push(op);
		return true;
	}
}

bool Controller::addList(Performance* p)
{
    if (list->findPerformance(p->getArtist()) != -1)
		return false;
	else {
		list->add(p);
        Operation op = Operation(ADD_LIST, p);
        undo.push(op);
		return true;
	}
}

bool Controller::undoOperation(){
    Performance* p = undo.top().getPerf();
    OperationType op = undo.top().getType();

    if(op == ADD){
        redo.push(undo.top());
        undo.pop();
        removePerformance(p->getArtist());
        return true;
    }
    else if(op == REMOVE){
        redo.push(undo.top());
        undo.pop();
        addPerformance(p->getArtist(), p->getCountry(), p->getDay(), p->getStage(), p->getLink());
        return true;
    }
    else if(op == ADD_LIST){
        redo.push(undo.top());
        undo.pop();
        removeList(p->getArtist());
        return true;
    }
    else if(op == REMOVE_LIST){
        redo.push(undo.top());
        undo.pop();
        addList(p);
        return true;
    }
    return false;
}

bool Controller::redoOperation()
{
    Performance* p = redo.top().getPerf();
    OperationType op = redo.top().getType();

    if(op == ADD){
        addPerformance(p->getArtist(), p->getCountry(), p->getDay(), p->getStage(), p->getLink());
        redo.pop();
        return true;
    }
    else if(op == REMOVE){
        removePerformance(p->getArtist());
        redo.pop();
        return true;
    }
    else if(op == ADD_LIST){
        addList(p);
        redo.pop();
        return true;
    }
    else if(op == REMOVE_LIST){
        removeList(p->getArtist());
        redo.pop();
        return true;
    }
}

void Controller::loadFile(std::string filePath)
{
    std::string extension;
    extension = filePath.substr(filePath.find_last_of(".") + 1);


    if(extension == "csv")
    {

        QFile file(QString::fromStdString(filePath));

            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << file.errorString();
            }

            string artist, country, stage, link;
            int day;
            while (!file.atEnd()) {
                QString line = file.readLine();
                QStringList strings = line.split(",");
                artist = strings.value(0).toStdString();
                country = strings.value(1).toStdString();
                day = strings.value(2).toInt();
                stage = strings.value(3).toStdString();
                link = strings.value(4).toStdString();

                Performance* p = new Performance(artist, country, day, stage, link);
                repo->add(p);

            }
            file.close();

    }

    else if(extension == "json")
    {
        string artist, country,stage, link;
        int day;

        QFile file(QString::fromStdString(filePath));
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument document = QJsonDocument::fromJson(jsonData);
        QJsonObject object = document.object();
        QJsonValue value = object.value(QString::fromStdString("performance"));
        QJsonArray array = value.toArray();
        foreach(const QJsonValue &v, array){
            artist = v.toObject().value("artist").toString().toUtf8().constData();
            country = v.toObject().value("country").toString().toUtf8().constData();
            day = v.toObject().value("day").toInt();
            stage = v.toObject().value("stage").toString().toUtf8().constData();
            link = v.toObject().value("link").toString().toUtf8().constData();
            Performance* p = new Performance(artist, country, day, stage, link);
            repo->add(p);
        }
        
    }
}

void Controller::saveJSONfile(string filePath)
{

       QFile save(QString::fromStdString("C:/Users/Irem/Desktop/OOP/Untold/jsonfile.json"));
        QJsonObject performance;
        QJsonArray array;

        for(int i = 0; i < repo->getLength() - 1; i++)
        {
            Performance* p = repo->getElems()[i];
            QJsonObject perf_obj;
            perf_obj["artist"] = QString::fromStdString( p->getArtist() );
            perf_obj["country"] = QString::fromStdString(p->getCountry());
            perf_obj["day"] = QString(p->getDay());
            perf_obj["stage"] = QString::fromStdString(p->getStage());
            perf_obj["link"] = QString::fromStdString(p->getLink());
            array.append(perf_obj);
          }
            performance.insert("performance", array);
            QJsonDocument document(performance);
            QString string = document.toJson();

            if(!save.open(QIODevice::WriteOnly))
                cout << "error";

            save.write(string.toLocal8Bit());

        save.close();
}

void Controller::saveCSVfile(string filePath)
{
	if (filePath == "" )
	{
        QFile file("C:/Users/Irem/Desktop/OOP/Untold_final/csvfileout.csv");

        if(file.open(QFile::WriteOnly))
        {
            QTextStream stream(&file);
            for (int i = 0; i < repo->getLength(); i++)
            {
                Performance* p = repo->getElems()[i];
                stream << QString::fromStdString(p->getArtist()) << "," << QString::fromStdString(p->getCountry()) << "," << QString(p->getDay()) << "," << QString::fromStdString(p->getStage()) << "," << QString::fromStdString(p->getLink()) << ", \n";
            }
        }
         else
            cout << "error \n";
   }
	else
	{ 
        QFile file("C:/Users/Irem/Desktop/OOP/Untold_final/csvfileout.csv");

        if(file.open(QFile::WriteOnly))
        {
            QTextStream stream(&file);
            for (int i = 0; i < repo->getLength() - 1; i++)
            {
                Performance* p = repo->getElems()[i];
                 stream << QString::fromStdString(p->getArtist()) << "," << QString::fromStdString(p->getCountry()) << "," << QString(p->getDay()) << "," << QString::fromStdString(p->getStage()) << "," << QString::fromStdString(p->getLink()) << ", \n";            }
        }
         else
            cout << "error \n";
	}

}



