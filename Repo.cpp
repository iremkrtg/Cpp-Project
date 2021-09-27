#include "Repo.h"
#include <stdlib.h>
#include "ItemNotFoundException.h"

using namespace std;

Repository::Repository()
{
	capacity = 0;
	length = 0;
	elems = nullptr;
}

Repository::Repository(int capacity1)
{
	this->capacity = capacity1;
	length = 0;
	this->elems = (Performance**)malloc(capacity * sizeof(Performance));
}

Repository::~Repository()
{
}


Performance** Repository::getElems()
{
	return elems;
}

int Repository::getCapacity()
{
	return capacity;
}

bool Repository::setCapacity(int capacity)
{
	this->capacity = capacity;
	return true;
}

int Repository::getLength()
{
	return length;
}

bool Repository::setLength(int length)
{
	this->length = length;
	return true;
}

void Repository::destroy()
{
	free(elems);
	length = 0;
	capacity = 0;
}

bool Repository::add(Performance* p)
{
		int actual = length;
		if (length == capacity) {
			int newCapacity = capacity * 2;
			elems = (Performance**)realloc(elems, newCapacity * sizeof(Performance*));
		}
		
		elems[length] = p;
		length++;
		if (length == actual + 1)
			return true;
		return false;


}

bool Repository::remove(Performance* p)
{
	int perfIndex = -1;
	int actual = length;
	for (int i = 0; i < length; i++)
        if (elems[i]->getArtist() == p->getArtist()) {
			perfIndex = i;
			break;
		}
	
	for (int i = perfIndex; i < length - 1; i++)
		elems[i] = elems[i + 1];

	length--;

	if (length == actual - 1)
		return true;
	return false;
				

}

int Repository::findPerformance(string findArtist)
{
	int i = 0;
	if(length > 0)
		for (i = 0; i < length; i++)
             if(elems[i]->getArtist() == findArtist)
				return i;

	return -1;
}

bool Repository::update(string artist, Performance* p)
{
	for(int i = 0; i < length; i++)
        if (elems[i]->getArtist() ==  artist) {
			elems[i] = p;
			return true;
		}
	return false;
}
