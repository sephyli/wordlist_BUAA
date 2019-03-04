#pragma once
#include "Word.h"
#include "WordSet.h"

class Data
{
public:
	Data(FILE* fpt);
	Data(char *words[], int len)
	~Data();
	WordSet ws;
private:
	int inrange(char c);
};

