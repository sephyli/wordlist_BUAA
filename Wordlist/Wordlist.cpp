#include "pch.h"
#include <iostream>
#include "Word.h"
#include "WordSet.h"
#include "Data.h"
#include "Mode.h"
#include "Searcher.h"
#include "Inputer.h"

using namespace std;

int main(int agrc, char* agrv[])
{
	bool rMode = false;
	bool hMode = false;
	bool tMode = false;
	bool wMaxMode = false;
	bool cMaxMode = false;
	char h = 0;
	char t = 0;
	char filePath[1000] = "\0";
	try {
		for (int i = 0; i < agrc; i++) {
			if (agrv[i][0] == '-') {
				switch (agrv[i][1])
				{
				case 'W':
				case 'w':
					wMaxMode = true;
					if (agrv[i][2] != '\0') 
						throw "最长单词模式命令过长！";
					break;
				case 'C':
				case 'c':
					cMaxMode = true;
					if (agrv[i][2] != '\0') 
						throw "最多字母模式命令过长！";
					break;
				case 'R':
				case 'r':
					rMode = true;
					if (agrv[i][2] != '\0') 
						throw "循环模式命令过长！";
					break;
				case 'H':
				case 'h':
					hMode = true;
					if (agrv[i][2] != '\0') 
						throw "首字母模式命令过长！";
					h = agrv[++i][0];
					if (agrv[i][1] != '\0')
						throw "首字母过长！";
					break;
				case 'T':
				case 't':
					tMode = true;
					if (agrv[i][2] != '\0') 
						throw "尾字母模式命令过长！";
					t = agrv[++i][0];
					if (agrv[i][1] != '\0')
						throw "尾字母过长！";
					break;
				default: 
					throw "命令行参数无法被理解！";
					break;
				}
			}
			if (i == agrc - 1) {
				int j;
				for (j = 0; agrv[i][j] != '\0'; j++) {
					filePath[j] = agrv[i][j];
				}
				filePath[j] = '\0';
			}
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
		exit(-1);
	}
	

	Mode *mode = new Mode();
	mode->Set(rMode, hMode, tMode, wMaxMode, cMaxMode, h, t);
	FILE *fin, *fout;
	int err = fopen_s(&fin, filePath, "r");
	fopen_s(&fout, "./solution.txt", "w");
	if (err != 0) {
		cout << "文件不存在!" << endl;
		exit(-1);
	}

	char *words[10000];
	Inputer *inputer = new Inputer();
	int wordNum = inputer->getWord(fin, words);

	Data *data = new Data(words, wordNum);
	Searcher *searcher = new Searcher(*data, *mode);
	if (searcher->exe()) {
		searcher->output(true, fout);
	}

	return 0;
}
