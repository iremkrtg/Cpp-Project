#pragma once
#include "Performance.h"
#include <vector>


class Repository {
public:
	Repository();
	Repository(int capacity1);
	~Repository();

	Performance** getElems();
	
	int getCapacity();
	bool setCapacity(int capacity);

	int getLength();
	bool setLength(int length);
	
	void destroy();

	bool add(Performance* p);

	bool remove(Performance* p);

    int findPerformance(string findArtist);

    bool update(string artist, Performance* p);

private:
	Performance** elems;
	int capacity;
	int length;

};
