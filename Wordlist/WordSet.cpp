#include "pch.h"
#include "WordSet.h"

WordSet::WordSet(){}

WordSet::~WordSet(){}

void WordSet::append(Word w) {
	bool suc = true;
	for (auto iter = this->set[w.head - 'a'].begin(); iter < this->set[w.head - 'a'].end(); iter++) {
		if (iter->s.compare(w.s) == 0) {
			suc = false;
		}
	}
	if (suc)
		this->set[w.head - 'a'].push_back(w);
}

//Word WordSet::getWord(char head) {
//
//}