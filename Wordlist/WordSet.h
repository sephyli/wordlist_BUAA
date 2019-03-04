#pragma once
#include "Word.h"
#include <vector>
class WordSet {
public:
	WordSet();
	~WordSet();
	void append(Word w);
	//Word getWord(char head);
// private:
	std::vector<Word> set[26][26];
};

