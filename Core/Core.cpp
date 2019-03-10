// Core.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Core.h"
extern "C" {
	int Core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
	{
		int ret = 0;
		Mode *mode = new Mode();
		mode->Set(enable_loop, head != 0, tail != 0, true, false, head, tail);
		Data *data = new Data(words, len);
		Searcher *searcher = new Searcher(*data, *mode);
		if (searcher->exe()) {
			ret = searcher->output(result);
		}
		return ret;
	}
	int Core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
	{
		int ret = 0;
		Mode *mode = new Mode();
		mode->Set(enable_loop, head != 0, tail != 0, false, true, head, tail);
		Data *data = new Data(words, len);
		Searcher *searcher = new Searcher(*data, *mode);
		if (searcher->exe()) {
			ret = searcher->output(result);
		}
		return ret;
	}
}
