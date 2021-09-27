#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Performance {
public:
	Performance();
    Performance(string artist1, string country1, int day1, string stage1, string link1);
	~Performance();

    string getArtist();
    bool setArtist(string artist);

    string getCountry();
    bool setCountry(string country);

	int getDay();
	bool setDay(int day);

    string getStage();
    bool setStage(string stage);

    string getLink();
    bool setLink(string link);

	virtual std::string toString();

private:
    string artist;
    string country;
	int day;
    string stage;
    string link;



};
