#pragma once
#include "Board.h"

class Input : public Board
{
protected:
	char row;
	char column;
	char value;
	int cnt;

public:
	int UserMode = 0;

	Input();
	void init();
	bool ExpectionCheck();
	bool DuplicateCheck();
	bool NumbofBlankCheck();
	char& FillintheBlank();
};
