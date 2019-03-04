#include "pch.h"
#include "Data.h"


Data::Data(FILE* fpt)
{
	char c = 0;
	char s[100] = "";
	int index = 0;
	c = fgetc(fpt);
	while (c != EOF) {
		if (inrange(c) != 0)
			s[index++] = c;
		else if(index != 0) {
			s[index] = '\0';
			Word w = Word(s, index);
			this->ws.append(w);
			index = 0;
		}
		c = fgetc(fpt);
	}
}
Data::Data(char *words[], int len) {
	for (int i = 0; i < len; i++) {
		Word w = Word(words[i], strlen(words[i]));
		this->ws.append(w);
	}
}

Data::~Data()
{
}

int Data::inrange(char c) {
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 2;
	else
		return 0;
}


