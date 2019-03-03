#pragma once
#include <string>
class Word {
public:
	Word(const char* s, int length);
	~Word();
	char head;
	char tail;
	int length;
	std::string s;
	bool use;
private:
};

