#include "pch.h"
#include "Data.h"


Data::Data(FILE* fpt)
{
	char c = 0;
	char s[100];
	int index = 0;
	fscanf_s(fpt, "%c", &c, 1);
	while (c != EOF) {
		if (inrange(c) != 0)
			s[index++] = c;
		else if(index != 0 ) {
			Word w = Word(s, index);
			this->ws.append(w);
			index = 0;
		}
		fscanf_s(fpt, "%c", &c, 1);
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


