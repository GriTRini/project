#include "pch.h"
#include "Board.h"
#include "Question.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Board::Board()
{
	colorset = new char *[BOARD_COLUME];
	for (int i = 0; i < BOARD_COLUME; i++)
	{
		colorset[i] = new char[BOARD_ROW];
		memset(colorset[i], 0, sizeof(char)*BOARD_ROW);
	}

	question = new char[81];
	userdata = new char[81];
}

char Board::init(char* array, char** data)
{
	int cnt = 0;
	for (int i = 0; i < COLUME; i++)
		for (int j = 0; j < ROW; j++)
		{
			if (data[i][j] == '0')
				array[cnt] = ' ';
			else
				array[cnt] = data[i][j];
			cnt++;
		}
	return *array;
}

void Board::input()
{
	init(question, questionsheet);
	init(userdata, worksheet);

	int count = 0;
	for (int i = 4; i < 21; ++i)
		for (int j = 7; j < 42; ++j)
			if (i % 2 == 0 && j % 4 == 3)
			{
				if (question[count] == ' ')
				{
					board[i][j] = userdata[count];
					colorset[i][j] = 'g';
				}
				else
				{
					board[i][j] = question[count];
					colorset[i][j] = 'y';
				}
				count++;
			}
}

void Board::printboard()
{
	input();

	system("cls");
	cout << endl << endl;
	for (int i = 0; i < BOARD_COLUME; i++)
	{
		for (int j = 0; j < BOARD_ROW; j++)
			if (colorset[i][j] == 'g')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				cout << board[i][j];
			}
			else if (colorset[i][j] == 'y')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
				cout << board[i][j];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MAGENTA);
				cout << board[i][j];
			}
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
}

Board::~Board()
{
	for (int i = 0; i < BOARD_COLUME; i++)
		delete[] colorset[i];
	delete[] colorset;

	delete[] userdata;
	delete[] question;
}
