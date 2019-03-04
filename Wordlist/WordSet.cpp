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
	if (suc) {
		//this->set[w.head - 'a'].push_back(w);
		if (this->set[w.head - 'a'].size() == 0)
			this->set[w.head - 'a'].push_back(w);
		else {
			bool insert = false;
			for (auto iter = this->set[w.head - 'a'].begin(); iter < this->set[w.head - 'a'].end(); iter++) {
				if (iter->tail == w.tail && iter->length <= w.length) {
					this->set[w.head - 'a'].insert(iter, 1, w);
					insert = true;
					break;
				}
				if (iter->tail < w.tail) {
					this->set[w.head - 'a'].insert(iter, 1, w);
					insert = true;
					break;
				}
			}
			if(!insert)
				this->set[w.head - 'a'].push_back(w);
		}
	}
}

//Word WordSet::getWord(char head) {
//
//}