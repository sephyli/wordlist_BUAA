#include "pch.h"
#include "WordSet.h"
WordSet::WordSet() {
}

WordSet::~WordSet(){}

void WordSet::append(Word w) {
	if (this->set[w.head - 'a'][w.tail - 'a'].size() == 0) {
		this->set[w.head - 'a'][w.tail - 'a'].push_back(w);
		return;
	}
	bool suc = true;
	for (auto iter = this->set[w.head - 'a'][w.tail - 'a'].begin(); iter < this->set[w.head - 'a'][w.tail - 'a'].end(); iter++) {
		if (iter->s.compare(w.s) == 0) {
			suc = false;
		}
	}
	if (suc) {
		bool insert = false;
		for (auto iter = this->set[w.head - 'a'][w.tail - 'a'].begin(); iter < this->set[w.head - 'a'][w.tail - 'a'].end(); iter++) {
			if (iter->length <= w.length) {
				this->set[w.head - 'a'][w.tail - 'a'].insert(iter, 1, w);
				insert = true;
				break;
			}
		}
		if(!insert)
			this->set[w.head - 'a'][w.tail - 'a'].push_back(w);
	}
}

//Word WordSet::getWord(char head) {
//
//}