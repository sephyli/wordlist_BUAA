#include "pch.h"
#include <iostream>
#include "Word.h"
#include "WordSet.h"
#include "Data.h"
#include "Mode.h"
#include "Searcher.h"

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
	for (int i = 0; i < agrc; i++) {
		if (agrv[i][0] == '-') {
			switch (agrv[i][1])
			{
			case 'W':
			case 'w':
				wMaxMode = true;
				if (agrv[i][2] != '\0')
					cout << "TOO MUCH LETTER FOR W" << endl;
				break;
			case 'C':
			case 'c':
				cMaxMode = true;
				if (agrv[i][2] != '\0')
					cout << "TOO MUCH LETTER FOR C" << endl;
				break;
			case 'R':
			case 'r':
				rMode = true;
				if (agrv[i][2] != '\0')
					cout << "TOO MUCH LETTER FOR R" << endl;
				break;
			case 'H':
			case 'h':
				hMode = true;			
				if (agrv[i][2] != '\0')
					cout << "TOO MUCH LETTER FOR HEAD" << endl;
				h = agrv[++i][0];
				break;
			case 'T':
			case 't':
				tMode = true;
				if (agrv[i][2] != '\0')
					cout << "TOO MUCH LETTER FOR TAIL" << endl;
				t = agrv[++i][0];
				break;
			default:
				cout << "PARAMETER CANNOT BE UNDERSTANDED" << endl;
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

	Mode *mode = new Mode();
	mode->Set(rMode, hMode, tMode, wMaxMode, cMaxMode, h, t);
	FILE *fin, *fout;
	int err = fopen_s(&fin, filePath, "r");
	fopen_s(&fout, "./solution.txt", "w");
	if (err != 0)
		cout << "FILE PATH ERROR!" << endl;
	Data *data = new Data(fin);
	cout << data->ws.getWordsNum() << endl;
	//return 0;
	Searcher *searcher = new Searcher(*data, *mode);
	if (searcher->exe()) {
		searcher->output(true, fout);
	}
	else {
		cout << "CANNOT FIND A WORD LIST" << endl;
	}

	return 0;
}
