#pragma once
#include "Word.h"
#include "WordSet.h"

class Data
{
public:
	Data();
	Data(FILE* fpt);
	Data(char *words[], int len);
	~Data();
	void reset();
	WordSet ws;
private:
	int inrange(char c);
};

