// CoreAPITest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Core.h"
#include <iostream>
using namespace std;
int main()
{
	char* input[4];
	char input1[100] = "end";
	char input2[100] = "of";
	char input3[100] = "the";
	char input4[100] = "world";
	input[0] = input1;
	input[1] = input2;
	input[2] = input3;
	input[3] = input4;
	char* result[4];
	for (int i = 0; i < 4; i++) {
		result[i] = new char(100);
	}
	int len = Core::gen_chain_word(input, 4, result, 0, 0, false);
	cout << len << endl;
}