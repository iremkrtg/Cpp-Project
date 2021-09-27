#pragma once
#include "Performance.h"



Performance::Performance()
{
    artist = "";
    country = "";
	day = -1;
    stage = "";
    link = "";

}

Performance::Performance(string artist1, string country1, int day1, string stage1, string link1)
{
    artist = artist1;
    country = country1;
	this->day = day1;
    this->stage = stage1;
    this->link = link1;

}

Performance::~Performance()
{
}

string Performance::getArtist()
{
	return artist;
}

bool Performance::setArtist(string artist)
{
    this->artist = artist;
	return true;
}

string Performance::getCountry()
{
	return country;
}

bool Performance::setCountry(string country)
{
    this->country = country;
	return true;
}

int Performance::getDay()
{
	return day;
}

bool Performance::setDay(int day)
{
	this->day = day;
	return true;
}

string Performance::getStage()
{
	return stage;
}

bool Performance::setStage(string stage)
{
    this->stage = stage;
    return true;
}

string Performance::getLink()
{
	return link;
}

bool Performance::setLink(string link)
{
    this->link = link;
	return true;
}

std::string Performance::toString()
{
	std::string str;
	str.append(artist);
	str.append(" - ");
	str.append(country);
	str.append(" - ");
	char day_str[] = "";
    strcpy(day_str, (char*)(day));
	str.append(day_str);
	str.append(" - ");
	str.append(link);

	return str;
}
