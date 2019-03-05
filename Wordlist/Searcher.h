#pragma once
#include "Data.h"
#include "Mode.h"
#include "Word.h"
#include "WordSet.h"
#include <vector>

class Searcher
{
public:
	Searcher(Data d, Mode m);
	~Searcher();
	Data data;
	Mode mode;
	std::vector<Word> maxWordList;
	std::vector<Word> tmpWordList;
	bool exe();
	void output(bool console, FILE* fout=NULL);

private:
	Word getWordFromVec(int headIndex, int tailIndex);
	void reset();
	bool judgeList();
	void search(char head);
	bool headChar[26];
	bool allUsed(int headIndex, int tailIndex);
};

