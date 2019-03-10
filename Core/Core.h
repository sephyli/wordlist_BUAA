#pragma once
#include "Word.h"
#include "WordSet.h"
#include "Data.h"
#include "Mode.h"
#include "Searcher.h"
class Core {
public:
	static __declspec(dllexport) int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	static __declspec(dllexport) int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
};
