#include "stdafx.h"
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
		Word w = this->getWordFromVec(head - 'a', i);
		this->search(w.tail);
		this->data.reset(w.s, head, w.tail);
		if (!tmpWordList.empty()) {
			this->tmpWordList.pop_back();
		}
		else {
			cout << "fuck!!!!!!" << endl;
		}
	}
	this->judgeList();
	this->reset(head);
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
	return Word();
}

bool Searcher::judgeList() {
	bool suc = true;

	if (this->mode.tailMode && this->tmpWordList.size() != 0) {
		int popCount = 0;
		for (auto iter = this->tmpWordList.end() - 1; ; iter--) {
			if (this->mode.tail != iter->tail) {
				popCount++;
			}
			else
				break;
			if (iter == this->tmpWordList.begin())
				break;
		}
		for (int i = 0; i < popCount; i++) {
			this->tmpWordList.pop_back();
		}
		if (this->tmpWordList.size() == 0)
			suc = false;
	}

	if (this->mode.wordNumMaxMode) {
		int maxNum = int(this->maxWordList.size());
		int tmpNum = int(this->tmpWordList.size());
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

	if(suc == true)
		this->maxWordList = this->tmpWordList;
	
	return suc;
}

void Searcher::reset(char tail) {
	this->headChar[tail - 'a'] = false;
}

void Searcher::output(bool console, FILE* fout){
	if (console) {
		for (auto iter = this->maxWordList.begin(); iter != this->maxWordList.end(); iter++) {
			std::cout << iter->s << std::endl;
		}
	}
	else {
		for (auto iter = this->maxWordList.begin(); iter != this->maxWordList.end(); iter++) {
			fprintf_s(fout, "%s\n", iter->s.c_str());
		}
		fclose(fout);
	}
}
int Searcher::output(char* result[]) {
	int i = 0;
	for (auto iter = this->maxWordList.begin(); iter != this->maxWordList.end(); iter++) {
		strcpy_s(result[i++], iter->length + 1, iter->s.c_str());
	}
	return i;
}
Searcher::~Searcher()
{
}


