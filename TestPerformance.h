#pragma once
#include "Performance.h"

class TestPerformance {
public:
	void testGetArtist();
	void testGetCountry();
	void testGetDay();
	void testGetStage();
	void TestGetLink();
private:
	Performance p;
	//void tearDown();
	void setUp();
};
