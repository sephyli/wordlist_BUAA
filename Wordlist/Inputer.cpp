#include "pch.h"
#include "Inputer.h"


Inputer::Inputer()
{
}

int Inputer::getWord(FILE* fpt, char *words[])
{
	char c = 0;
	char s[100] = "";
	int index = 0, wordNum = 0;
	c = fgetc(fpt);
	while (c != EOF || index != 0) {
		if (inrange(c) != 0)
			s[index++] = c;
		else if (index != 0) {
			s[index] = '\0';
			words[wordNum] = (char*)malloc(100 * sizeof(char));
			strcpy_s(words[wordNum++], index+1,s);
			//words[wordNum++] = s;
			index = 0;
			if (c == EOF)
				break;
		}
		c = fgetc(fpt);
	}
	return wordNum;
}


int Inputer::inrange(char c) {
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 2;
	else
		return 0;
}

Inputer::~Inputer()
{
}
