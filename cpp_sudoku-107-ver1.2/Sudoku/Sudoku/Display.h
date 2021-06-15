#pragma once
#include <ctime>

class Display
{
protected:
	char **questionsheet;
	char **worksheet;
public:
	bool Check(int data);
	void ending(clock_t start, clock_t end);
	void shutdown();
};