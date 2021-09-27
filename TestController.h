#pragma once
#include "Controller.h"
#include "Repo.h"

class TestController {
public:
	void testAdd();
	void testAddExisting();
	void testRemove();
	void testRemoveNonexistent();
	void testUpdate();

private:
	Controller ctrl;
	void tearDown();
	void setUp();
};