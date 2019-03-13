// CoreAPITest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Core.h"
#include "Inputer.h"
#include <iostream>
using namespace std;
int main()
{
	FILE *fin;
	fopen_s(&fin, "./test.txt", "r");

	char *words[10000], *result[27];
	Inputer *inputer = new Inputer();
	int wordNum = inputer->getWord(fin, words);
	for (int i = 0; i < 27; i++) {
		result[i] = new char(100);
	}

	int len = Core::gen_chain_word(words, wordNum, result, 0, 0, false);
	cout << len << endl;
}