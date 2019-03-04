#include "pch.h"
#include "Mode.h"


Mode::Mode()
{
	this->recurMode =false;
	this->headMode =false;
	this->tailMode =false;
	this->wordNumMaxMode =false;
	this->charNumMaxMode=false;
	this->head = 0;
	this->tail = 0;
}


Mode::~Mode()
{
}

void Mode::Set(bool rMode, bool hMode,bool tMode, bool wMaxMode, bool cMaxMode,char h, char t) {
	this->recurMode = rMode;
	this->headMode = hMode;
	this->tailMode = tMode;
	this->wordNumMaxMode = wMaxMode;
	this->charNumMaxMode = cMaxMode;
	this->head = h;
	this->tail = t;
}
