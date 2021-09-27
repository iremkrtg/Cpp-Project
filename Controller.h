#pragma once
#include "Repo.h"
#include "Operation.h"

#include <stack>

using namespace std;

class Controller {
public:
	Controller();
    Controller(Repository* repo1, Repository* list1, std::stack<Operation> undo1, std::stack<Operation> redo1);
	~Controller();

	void loadPerformance();

	Repository* getRepo();
	Repository* getList();
    std::stack<Operation>* getUndo();
    std::stack<Operation>* getRedo();

    bool addPerformance(string artist, string country, int day, string stage, string link);

    void removePerformance(string artist);

    void updatePerformance(string givenArtist, string artist, string country, int day, string stage, string link);

	void displayPerformance();

	void displayList();

    void displayPerfStage(string stage);

	bool addList(Performance* p);

    bool removeList(string artist);

   void loadFile(std::string filePath);

   void saveCSVfile(string filePath);

   void saveJSONfile(string filePath);

   bool undoOperation();

   bool redoOperation();


private:
	Repository* repo;
    Repository* list;
    std::stack<Operation> undo;
    std::stack<Operation> redo;

};


