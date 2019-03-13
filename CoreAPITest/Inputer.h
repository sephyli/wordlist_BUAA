#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
class Inputer {
public:
	Inputer();
	~Inputer();
	int getWord(FILE* fpt, char *words[]);
	int inrange(char c);
};

