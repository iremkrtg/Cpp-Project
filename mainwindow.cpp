#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSize>
#include <QDebug>

MainWindow::MainWindow(Controller* ctrl, QWidget *parent)
    : QMainWindow(parent)
    , m_controller(ctrl)
{
    //ui->setupUi(this);
    m_widget = new QWidget();
    m_layout = new QGridLayout();
    m_admin = new QPushButton("ADMIN");
    m_user = new QPushButton("USER");
    m_data = new QLabel("Please select which data you want to be loaded.");
    load_ctrl = new QPushButton("Load data.");
    file_name = new QLineEdit("File name.");
    load_file = new QPushButton("Load from file.");


    file_name->setMaximumWidth(274);
    m_layout->addWidget(m_data, 0 , 1, 1, 1);
    m_layout->addWidget(load_ctrl, 1, 0, 1, 1);
    m_layout->addWidget(file_name, 1, 1, 1, 1);
    m_layout->addWidget(load_file, 1, 2, 1, 1);
    m_layout->addWidget(m_admin, 2, 0, 1, 1);
    m_layout->addWidget(m_user, 2, 2, 1, 1);


    connect(m_admin, &QPushButton::clicked, this, &MainWindow::onAdminPressed, Qt::ConnectionType::UniqueConnection);
    connect(m_user, &QPushButton::clicked, this, &MainWindow::onUserPressed);
    connect(load_ctrl, &QPushButton::pressed, this, &MainWindow::onLoadPressed);
    connect(load_file, &QPushButton::pressed, this, &MainWindow::onFilePressed);

            //connect(buttonAdd, &QPushButton:: pressed, this, &PlantsGUI:: onAddPlantPressed);

    m_widget->setWindowTitle("Untold GUI");
    m_widget->setMinimumSize(QSize(800, 200));
    m_widget->setLayout(m_layout);
    this->setCentralWidget(m_widget);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAdminPressed()
{
    m_adminWindow = new AdminWindow();
    close_admin = new QPushButton("Close admin window");
    connect(close_admin, &QPushButton::pressed, this, &MainWindow::onCloseAdminPressed);

    QPushButton* undoButtom = new QPushButton("undo");
    connect(undoButtom, &QPushButton::clicked, this, &MainWindow::onUndoPressedAdmin);
    QPushButton* redoButton = new QPushButton("Redo");
    connect(redoButton, &QPushButton::clicked, this, &MainWindow::onRedoPressedAdmin);

   undoButtom->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_X));
   redoButton->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));

    QWidget* admin_widget = new QWidget();
    QGridLayout* admin_layout = new QGridLayout();



    //add widget
    add_widget = new QWidget();
    add_layout = new QGridLayout();
    addWidget_label = new QLabel( "Add a performance.");
    artist_label = new QLabel("Artist: ");
    artist = new QLineEdit();
   country_label = new QLabel("Country: ");
    country = new QLineEdit();
    day_label = new QLabel("Day: ");
    day = new QLineEdit();
    stage_label = new QLabel("Stage: ");
    stage = new QLineEdit();
    link_label = new QLabel("Link: ");
    link = new QLineEdit();
    add_performance = new QPushButton("Add performance.");

    add_layout->addWidget(addWidget_label, 0, 0, 1, 1);
    add_layout->addWidget(artist_label, 1, 0, 1, 1);
    add_layout->addWidget(artist, 1, 1, 1, 1);
    add_layout->addWidget(country_label, 2, 0, 1, 1);
    add_layout->addWidget(country, 2, 1, 1, 1);
    add_layout->addWidget(day_label, 3, 0, 1, 1);
    add_layout->addWidget(day, 3, 1, 1, 1);
    add_layout->addWidget(stage_label, 4, 0, 1, 1);
    add_layout->addWidget(stage, 4, 1, 1, 1);
    add_layout->addWidget(link_label, 5, 0, 1, 1);
    add_layout->addWidget(link, 5, 1, 1, 1);
    add_layout->addWidget(add_performance, 6, 0, 1, 2);

    connect(add_performance, &QPushButton:: pressed, this, &MainWindow:: onAddPressed);


    add_widget->setLayout(add_layout);

    //remove widget
    remove_widget = new QWidget();
    remove_layout = new QGridLayout();
    remove_label = new QLabel("Remove a performance.");
    artist_remove = new QLabel("Artist to remove: ");
    input_remove = new QLineEdit();
    remove_performance = new QPushButton("Remove performance.");

    remove_layout->addWidget(remove_label, 0, 0, 1, 2);
    remove_layout->addWidget(artist_remove, 1, 0, 1, 1);
    remove_layout->addWidget(input_remove, 1, 1, 1, 1);
    remove_layout->addWidget(remove_performance, 2, 0, 1, 2);

    connect(remove_performance, &QPushButton::pressed, this, &MainWindow::onRemovePressed);

    remove_widget->setLayout(remove_layout);

    //update widget
    update_widget = new QWidget();
    update_layout = new QGridLayout();
    update_label = new QLabel( "Update a performance.");
    artist_to_update = new QLabel("Artist to update: ");
    artist_to_up = new QLineEdit();
    artist_up = new QLabel("Artist: ");
    artist_new = new QLineEdit();
   country_up = new QLabel("Country: ");
    country_new= new QLineEdit();
    day_up = new QLabel("Day: ");
    day_new = new QLineEdit();
    stage_up = new QLabel("Stage: ");
    stage_new = new QLineEdit();
    link_up = new QLabel("Link: ");
    link_new = new QLineEdit();
    update_performance = new QPushButton("Update performance.");

    update_layout->addWidget(update_label, 0, 0, 1, 2);
    update_layout->addWidget(artist_to_update, 1, 0, 1, 1);
    update_layout->addWidget(artist_to_up, 1, 1, 1, 1);
    update_layout->addWidget(artist_up, 2, 0, 1, 1);
    update_layout->addWidget(artist_new, 2, 1, 1, 1);
    update_layout->addWidget(country_up, 3, 0, 1, 1);
    update_layout->addWidget(country_new, 3, 1, 1, 1);
    update_layout->addWidget(day_up, 4, 0, 1, 1);
    update_layout->addWidget(day_new, 4, 1, 1, 1);
    update_layout->addWidget(stage_up, 5, 0, 1, 1);
    update_layout->addWidget(stage_new, 5, 1, 1, 1);
    update_layout->addWidget(link_up, 6, 0, 1, 1);
    update_layout->addWidget(link_new, 6, 1, 1, 1);
    update_layout->addWidget(update_performance,7, 0, 1, 2);

    connect(update_performance, &QPushButton::pressed, this, &MainWindow::onUpdatePressed);

    update_widget->setLayout(update_layout);

    //display list
    display_repo = new QListWidget(this);
    populate();

    admin_layout->addWidget(add_widget, 0, 0, 1, 1);
    admin_layout->addWidget(remove_widget, 0, 1, 1, 1);
    admin_layout->addWidget(update_widget, 0, 2, 1, 1);
    admin_layout->addWidget(display_repo, 1, 0, 1, 3);
    admin_layout->addWidget(close_admin, 2, 2 , 1 , 1);
    admin_layout->addWidget(undoButtom, 2, 0, 1, 1);
    admin_layout->addWidget(redoButton, 2, 1, 1, 1);

    admin_widget->setMinimumSize(QSize(1000, 200));
    admin_widget->setLayout(admin_layout);


    m_adminWindow->setCentralWidget(admin_widget);

    qDebug() << "before show";
    m_adminWindow->show();

}

void MainWindow::onLoadPressed()
{
    m_controller->loadPerformance();
}

void MainWindow::onFilePressed()
{
    QString input_file = file_name->text();
    m_controller->loadFile(input_file.toStdString());

}

void MainWindow::onAddPressed()
{
    string artist_str = artist->text().toStdString();
    string country_str = country->text().toStdString();
    int day_int = day->text().toInt();
    string stage_str = stage->text().toStdString();
    string link_str = link->text().toStdString();

    m_controller->addPerformance(artist_str, country_str, day_int, stage_str, link_str);
    m_controller->saveCSVfile("C:/Users/Irem/Desktop/OOP/Untold_final/csvfileout.csv");

   new QListWidgetItem(tr(artist_str.c_str()), display_repo);

}

void MainWindow::onRemovePressed()
{
    string artist_str = input_remove->text().toStdString();

    int index = m_controller->getRepo()->findPerformance(artist_str);

    m_controller->removePerformance(artist_str);
    m_controller->saveCSVfile("C:/Users/Irem/Desktop/OOP/Untold_final/csvfileout.csv");


    display_repo->takeItem(index);
}

void MainWindow::onUpdatePressed()
{
    string update_artist = artist_to_up->text().toStdString();
    string artist_str = artist_new->text().toStdString();
    string country_str = country_new->text().toStdString();
    int day_int = day_new->text().toInt();
    string stage_str = stage_new->text().toStdString();
    string link_str = link_new->text().toStdString();

    m_controller->updatePerformance(update_artist, artist_str, country_str, day_int, stage_str, link_str);

    populate();
}
void MainWindow::populate()
{
    display_repo->clear();

    for(int i = 0; i < m_controller->getRepo()->getLength(); i++)
        new QListWidgetItem(tr(m_controller->getRepo()->getElems()[i]->getArtist().c_str()), display_repo);
}

void MainWindow::onCloseAdminPressed()
{
    m_adminWindow->close();
}

void MainWindow::onUserPressed()
{
    user_window = new AdminWindow;

    user_window->setWindowTitle("User");

    QPushButton* undoButtom = new QPushButton("undo");
    connect(undoButtom, &QPushButton::clicked, this, &MainWindow::onUndoPressedUser);
    QPushButton* redoButton = new QPushButton("redo");
    connect(redoButton, &QPushButton::clicked, this, &MainWindow::onRedoPressedUser);

    undoButtom->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_X));
    redoButton->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));

    QWidget* user_widget = new QWidget();
    QGridLayout* user_layout = new QGridLayout();

    wishlist = new QLabel("Wish list");
    repo_label = new QLabel("Untold performances");
    artist_wish = new QLineEdit();
    add_wish = new QPushButton("Add performance to wishlist");
    artist_wish_remove = new QLineEdit();
    remove_wish = new QPushButton("Remove performance from wishlist");
    close_user = new QPushButton("Close user window");

    repository = new QListWidget();
    populateWish();

//    connect(repository, repository->itemClicked(), this, &MainWindow::onItemClicked);
//    repository->itemPressed()

    wish_list = new QListWidget();

    connect(add_wish, &QPushButton::pressed, this, &MainWindow::onAddWish);
    connect(remove_wish, &QPushButton::pressed, this, &MainWindow::onRemoveWish);
    connect(close_user, &QPushButton::pressed, this, &MainWindow::onCloseUserPressed);

    user_layout->addWidget(repo_label, 0, 0, 1, 1);
    user_layout->addWidget(wishlist, 0, 1, 1, 1);
    user_layout->addWidget(repository, 1, 0, 1, 1);
    user_layout->addWidget(artist_wish, 2, 0, 1 , 1);
    user_layout->addWidget(add_wish, 2, 1, 1, 1);
    user_layout->addWidget(artist_wish_remove, 3, 0, 1, 1);
    user_layout->addWidget(remove_wish, 3, 1, 1, 1);
    user_layout->addWidget(wish_list, 1, 1, 1, 1);
    user_layout->addWidget(close_user, 6, 1, 1, 2);
    user_layout->addWidget(undoButtom, 5, 0, 1, 1);
    user_layout->addWidget(redoButton, 5, 1, 1, 1);


    user_widget->setMinimumSize(QSize(1000, 200));
    user_widget->setLayout(user_layout);


    user_window->setCentralWidget(user_widget);


    user_window->show();


}

void MainWindow::onAddWish()
{
    string wishartist = artist_wish->text().toStdString();
    int index = m_controller->getRepo()->findPerformance(wishartist);
    m_controller->addList(m_controller->getRepo()->getElems()[index]);
    new QListWidgetItem(tr(m_controller->getRepo()->getElems()[index]->getArtist().c_str()), wish_list);
}

void MainWindow::onRemoveWish()
{
    string wishartist = artist_wish_remove->text().toStdString();
    int index = m_controller->getList()->findPerformance(wishartist);
    m_controller->removeList(wishartist);
    wish_list->takeItem(index);
}

void MainWindow::onCloseUserPressed()
{
    user_window->close();
}

void MainWindow::populateWish()
{
    repository->clear();

    for(int i = 0; i < m_controller->getRepo()->getLength(); i++)
        new QListWidgetItem(tr(m_controller->getRepo()->getElems()[i]->getArtist().c_str()), repository);
}

void MainWindow::populateList()
{
    wish_list->clear();

    for(int i = 0; i < m_controller->getList()->getLength(); i++)
        new QListWidgetItem(tr(m_controller->getList()->getElems()[i]->getArtist().c_str()), wish_list);
}

void MainWindow::onUndoPressedAdmin()
{
    m_controller->undoOperation();
    populate();
}

void MainWindow::onUndoPressedUser(){
    m_controller->undoOperation();
    populateList();
}

void MainWindow::onRedoPressedAdmin(){
    m_controller->redoOperation();
    populate();
}

void MainWindow::onRedoPressedUser(){
    m_controller->redoOperation();
    populateList();
}
