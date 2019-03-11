#include "pch.h"
#include "Data.h"

using namespace std;

Data::Data()
{
}

//Data::Data(FILE* fpt)
//{
//	char c = 0;
//	char s[100] = "";
//	int index = 0;
//	c = fgetc(fpt);
//	while (c != EOF || index != 0) {
//		if (inrange(c) != 0)
//			s[index++] = c;
//		else if(index != 0) {
//			s[index] = '\0';
//			Word w = Word(s, index);
//			this->ws.append(w);
//			index = 0;
//			if (c == EOF)
//				break;
//		}
//		c = fgetc(fpt);
//	}
//}
Data::Data(char *words[], int len) {
	for (int i = 0; i < len; i++) {
		Word w = Word(words[i], int(strlen(words[i])));
		this->ws.append(w);
	}
}

void Data::reset(string s, char head, char tail) {
	if (s.length() == 0) {
		return;
	}
	for (auto iter = this->ws.set[head - 'a'][tail - 'a'].begin(); iter != this->ws.set[head - 'a'][tail - 'a'].end(); iter++)
		if (iter->s == s)
			iter->use = false;
}

//int Data::inrange(char c) {
//	if (c >= 'a' && c <= 'z')
//		return 1;
//	else if (c >= 'A' && c <= 'Z')
//		return 2;
//	else
//		return 0;
//}


Data::~Data()
{
}


