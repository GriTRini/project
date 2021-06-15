#include "pch.h"
#include "Question.h"
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

Question::Question()
{
	this->questionsheet = new char*[ROW];
	for (int i = 0; i < 9; i++)
	{
		questionsheet[i] = new char[COLUME];
		memset(questionsheet[i], 0, sizeof(char) * COLUME);
	}

	this->worksheet = new char*[ROW];
	for (int i = 0; i < 9; i++)
	{
		worksheet[i] = new char[COLUME];
		memset(worksheet[i], 0, sizeof(char) * COLUME);
	}
}

char Question::Generate(int NumberOfBlank, char **answer)
{
	this->NumberOfBlank = NumberOfBlank;

	for (int i = 0; i < COLUME; ++i)
		for (int j = 0; j < ROW; ++j)
			this->questionsheet[i][j] = answer[i][j];

	srand(time(0));
	for (int k = 0; k < NumberOfBlank; ++k)
	{
		int i = rand() % COLUME;
		int j = rand() % ROW;

		if (questionsheet[i][j] == '0')
			--k;
		else
			questionsheet[i][j] = '0';
	}
	return **questionsheet;
}

char Question::reset()
{
	for (int i = 0; i < COLUME; i++)
		for (int j = 0; j < ROW; j++)
			worksheet[i][j] = '0';
	cnt = 0;
	return **worksheet;
}

Question::~Question()
{
	for (int i = 0; i < COLUME; ++i)
		delete[] questionsheet[i];
	delete[] questionsheet;

	for (int i = 0; i < COLUME; i++)
		delete[] worksheet[i];
	delete[] worksheet;
}