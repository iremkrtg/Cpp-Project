#include "TestPerformance.h"
#include "Performance.h"
#include <assert.h>
#include <string.h>

void TestPerformance::testGetArtist()
{
	Performance p = Performance((char*)"Artist name", (char*)"Country", 1, (char*)"Stage", (char*)"Link");
	assert(p.getArtist() == "Artist name");
}

void TestPerformance::testGetCountry()
{
	setUp();
	assert(p.getCountry() == "Country");
}

void TestPerformance::testGetDay()
{
	Performance p = Performance((char*)"Artist name", (char*)"Country", 1, (char*)"Stage", (char*)"Link");
	assert(p.getDay() == 1);
}

void TestPerformance::testGetStage()
{
	setUp();
	assert(p.getStage() == "Stage");
}

void TestPerformance::TestGetLink()
{
	setUp();
	assert(p.getLink() == "Link");
}

void TestPerformance::setUp()
{
	Performance p = Performance((char*)"Artist name", (char*)"Country", 1, (char*)"Stage", (char*)"Link");
}
