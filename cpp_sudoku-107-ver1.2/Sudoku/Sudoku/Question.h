#pragma once
#include "Level.h"
#include "Answer.h"

class Question
{
protected:
	char **questionsheet;
	char **worksheet;
	int NumberOfBlank;
	int cnt;

public:
	Question();
	char Generate(int NumberOfBlank, char** answer);
	char reset();
	~Question();
};