#include "stdafx.h"
#include "CppUnitTest.h"
#include "Core.h"
#include "Inputer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestNonRecur)
		{
			FILE *fin;
			fopen_s(&fin, "../test/testfile.txt", "r");

			char *words[10000], *result[27];
			Inputer *inputer = new Inputer();
			int wordNum = inputer->getWord(fin, words);
			for (int i = 0; i < 27; i++) {
				result[i] = new char(100);
			}
			int len = 0;
			len = Core::gen_chain_word(words, wordNum, result, 0, 0, true);
			Assert::AreEqual(len, 4);
		}

		TEST_METHOD(Ture)
		{
			int len = 4;
			Assert::AreEqual(len, 4);
		}

	};
}