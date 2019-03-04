#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Wordlist/Data.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordlistUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
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
			Assert::AreEqual((int)ws.set['h'-'a'].size(), 4);
		}

	};
}