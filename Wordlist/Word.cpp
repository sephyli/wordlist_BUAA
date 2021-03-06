#pragma once
#include "pch.h"
#include "Word.h"
#include <string>

Word::Word(const char* s, int length) {
	if (length > 100) {
		throw "Word too long";
	}
	char s_tmp[100] = "\0";
	for (int i = 0; i <= length; i++) {
		if ('A' <= s[i] && s[i]<= 'Z') {
			s_tmp[i] = s[i] + 'a' - 'A';
		}
		else {
			s_tmp[i] = s[i];
		}
	}
	this->s = s_tmp;
	this->head = s_tmp[0];
	this->length = length;
	this->tail = s_tmp[length < 1 ? 0 : length - 1];
	this->use = false;
}


Word::~Word() {

}
