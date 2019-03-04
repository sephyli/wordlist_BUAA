#pragma once
class Mode
{
public:
	Mode();
	~Mode();
	void Set(bool rMode = false, bool hMode = false, bool tMode = false,
		bool wMaxMode = false, bool cMaxMode = false,
		char h = 0, char t = 0);
	bool recurMode;
	bool headMode;
	bool tailMode;
	bool wordNumMaxMode;
	bool charNumMaxMode;
	char head;
	char tail;
};

