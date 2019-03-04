#include "pch.h"
#include <iostream>
#include "Word.h"
#include "WordSet.h"
#include "Data.h"
#include "Mode.h"

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
			case 'w':
				wMaxMode = true;
				break;
			case 'c':
				cMaxMode = true;
				break;
			case 'r':
				rMode = true;
				break;
			case 'h':
				hMode = true;
				h = agrv[++i][0];
				if (agrv[i][1] != '\0')
					cout << "TOO MUCH LETTER FOR HEAD" << endl;
				break;
			case 't':
				tMode = true;
				t = agrv[++i][0];
				if (agrv[i][1] != '\0')
					cout << "TOO MUCH LETTER FOR TAIL" << endl;
				break;
			default:
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

	Mode mode = Mode();
	mode.Set(rMode, hMode, tMode, wMaxMode, cMaxMode, h, t);
	FILE* fpt;
	int err = fopen_s(&fpt, filePath, "r");
	if (err != 0)
		cout << "FILE PATH ERROR!" << endl;
	Data d = Data(fpt);


	return 0;
}
