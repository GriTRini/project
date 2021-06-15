#include "pch.h"
#include "Answer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Answer::Answer()
{
	answer = new char *[COLUME];
	for (int i = 0; i < ROW; i++)
		answer[i] = new char[ROW];
}

char** Answer::Generate() {
	int count = 0;
	int GameNumber = rand() % GAMECOUNT - 1;
	for (int i = 0; i < COLUME; ++i)
		for (int j = 0; j < ROW; ++j) {
			answer[i][j] = RandomAnswer[GameNumber][count];
			++count;
		}
	return this->answer;
}

Answer::~Answer() {

	for (int i = 0; i < COLUME; i++)
		delete[] answer[i];
	delete answer;
}