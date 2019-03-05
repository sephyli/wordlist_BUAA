#include "pch.h"
#include "Searcher.h"
#include <iostream>


Searcher::Searcher(Data d, Mode m)
{
	this->data = d;
	this->mode = m;
	for (int i = 0; i < 26; i++)
		this->headChar[i] = false;
}

bool Searcher::exe() 
{
	if (this->mode.headMode) 
		this->search(this->mode.head);
	else{
		for (int i = 0; i < 26; i++) {
			this->search('a' + i);
		}
	}
	return (this->maxWordList.size() != 0);
}

void Searcher::search(char head)
{
	this->headChar[head - 'a'] = true;
	
	for (int i = 0; i < 26; i++) {
		if (this->headChar[i] == true && !this->mode.recurMode)
			continue;
		if (this->allUsed(head-'a', i))
			continue;
		char newWordTail = this->getWordFromVec(head - 'a', i).tail;
		this->search(newWordTail);
	}

	this->judgeList();
	this->reset();
	this->data.reset();

	return;
}

bool Searcher::allUsed(int headIndex, int tailIndex) {
	for (auto iter = this->data.ws.set[headIndex][tailIndex].begin(); iter != this->data.ws.set[headIndex][tailIndex].end(); iter++) {
		if (iter->use == false) {
			return false;
		}
	}
	return true;
}

Word Searcher::getWordFromVec(int headIndex, int tailIndex) {
	for (auto iter = this->data.ws.set[headIndex][tailIndex].begin(); iter != this->data.ws.set[headIndex][tailIndex].end(); iter++) {
		if (iter->use != true) {
			iter->use = true;
			this->tmpWordList.push_back(*iter);
			return *iter;
		}
	}
}

bool Searcher::judgeList() {
	bool suc = true;

	if (this->mode.wordNumMaxMode) {
		int maxNum = this->maxWordList.size();
		int tmpNum = this->tmpWordList.size();
		if (maxNum >= tmpNum)
			suc = false;
	}
	else if (this->mode.charNumMaxMode) {
		int maxNum = 0, tmpNum = 0;
		for (auto iter = this->maxWordList.begin(); iter != this->maxWordList.end(); iter++) {
			maxNum += iter->length;
		}
		for (auto iter = this->tmpWordList.begin(); iter != this->tmpWordList.end(); iter++) {
			tmpNum += iter->length;
		}
		if (maxNum >= tmpNum)
			suc = false;
	}
	if (this->mode.tailMode && this->tmpWordList.size()!= 0) {
		if (this->mode.tail != this->tmpWordList[this->tmpWordList.size()-1].tail)
			suc = false;
	}

	if(suc == true)
		this->maxWordList = this->tmpWordList;
	
	return suc;
}

void Searcher::reset() {
	this->tmpWordList.clear();
	for (int i = 0; i < 26; i++) {
		this->headChar[i] = false;
	}
}

void Searcher::output(bool console, FILE* fout){
	if (console) {
		for (auto iter = this->maxWordList.begin(); iter != this->maxWordList.end(); iter++) {
			std::cout << iter->s << std::endl;
		}
	}
	else {
		for (auto iter = this->maxWordList.begin(); iter != this->maxWordList.end(); iter++) {
			fprintf_s(fout, "%s", iter->s);
		}
	}
}

Searcher::~Searcher()
{
}


