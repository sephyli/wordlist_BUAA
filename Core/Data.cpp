#include "stdafx.h"
#include "Data.h"
#include <iostream>
using namespace std;

Data::Data()
{
}

Data::Data(char *words[], int len) {
	for (int i = 0; i < len; i++) {
		Word w = Word(words[i], int(strlen(words[i])));
		this->ws.append(w);
	}
}

void Data::reset(string s, char head, char tail) {
	if (s.length() == 0) {
		return;
	}
	for (auto iter = this->ws.set[head - 'a'][tail - 'a'].begin(); iter != this->ws.set[head - 'a'][tail - 'a'].end(); iter++)
		if (iter->s == s)
			iter->use = false;
}

Data::~Data()
{
}


