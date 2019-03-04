// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Word.h"
#include "WordSet.h"

using namespace std;

int main()
{
	char w1[100] = "hello";
	char w2[100] = "hoooooo";
	char w3[100] = "heeeeee";
	char w4[100] = "hppp";

	Word W1 = Word(w1, 5);
	Word W2 = Word(w2, 7);
	Word W3 = Word(w3, 7);
	Word W4 = Word(w4, 4);

	WordSet ws = WordSet();
	ws.append(W1);
	ws.append(W2);
	ws.append(W3);
	ws.append(W4);


	return 0;
}
