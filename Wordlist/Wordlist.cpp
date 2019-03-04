// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Word.h"
#include "WordSet.h"
#include "Data.h"

using namespace std;

int main()
{
	FILE* fpt;
	int err = fopen_s(&fpt, "../test/testfile.txt", "r");
	if (err != 0)
		cout << "FILE PATH ERROR!" << endl;
	Data d = Data(fpt);


	return 0;
}
