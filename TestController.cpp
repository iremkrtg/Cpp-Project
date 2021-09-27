#include "TestController.h"
#include "Performance.h"
#include "Controller.h"
#include <string.h>
#include <assert.h>

void TestController::testAdd()
{
	setUp();

	char artist[] = ""; char country[] = ""; char stage[] = ""; char link[] = "";
	int day = 1;

	strcpy(artist, "Anonim");
	strcpy(country, "Unknown");
	strcpy(stage, "Main");
	strcpy(link, "https://untold.com/");

	ctrl.addPerformance(artist, country, day, stage, link);

	assert(ctrl.getRepo()->getLength() == 1);

	tearDown();
}

void TestController::testAddExisting()
{
	setUp();

	char artist[] = ""; char country[] = ""; char stage[] = ""; char link[] = "";
	int day = 1;

	strcpy(artist, "Anonim");
	strcpy(country, "Unknown");
	strcpy(stage, "Main");
	strcpy(link, "https://untold.com/");

	ctrl.addPerformance(artist, country, day, stage, link);
	ctrl.addPerformance(artist, country, day, stage, link);

	assert(ctrl.getRepo()->getLength() == 1);

	tearDown();

}

void TestController::testRemove()
{
	setUp();

	ctrl.addPerformance((char*)"New artist",(char*) "Unknown", 2, (char*)"Main", (char*)"https://untold.com/");

	ctrl.removePerformance((char*)"New artist");

	assert(ctrl.getRepo()->getLength() == 0);

	tearDown();

}

void TestController::tearDown()
{
	ctrl.getRepo()->destroy();
}

void TestController::setUp()
{
	const int repoSize = 100;
	const int listSize = 10;
	Repository repo = Repository(repoSize);
	Repository list = Repository(listSize);
    std::stack<Operation> undo;
    std::stack<Operation> redo;
    ctrl = Controller(&repo, &list, undo, redo);
}


