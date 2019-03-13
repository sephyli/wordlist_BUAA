#pragma once
#include "Word.h"
#include "WordSet.h"

using namespace std;

class Data
{
public:
	Data();
	Data(char *words[], int len);
	~Data();
	void reset(string s, char head, char tail);
	WordSet ws;
};
