#include "pch.h"
#include "Windows.h"
#include "Level.h"
#include "input.h"
#include "Display.h"

#include <mmsystem.h>
#include <ctime>
#include <iostream>

#pragma comment(lib, "Winmm.lib")

using namespace std;

int main()
{
	system("mode con: cols=92 lines=30");
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	clock_t start, end;

	Answer answer;
	Level level;
	Input data;
	Display ending;

	while (true)
	{
		data.Generate(level.DecisionBlankNum(), answer.Generate());
		data.printboard();
		start = clock();

		while (true)
		{
			data.init();
			if (data.UserMode == RETURN_TO_MAIN || data.UserMode == EXIT_GAME)
				break;
			else if (data.UserMode == RESET_GAME)
				data.reset();
			else
			{
				if (data.ExpectionCheck() == true && data.DuplicateCheck() == true)
					data.FillintheBlank();
				if (data.NumbofBlankCheck() == true)
				{
					ending.Check(data.UserMode);
					break;
				}
			}
			data.printboard();
		}
		if (ending.Check(data.UserMode) == true)
		{
			ending.shutdown();
			break;
		}
	}
	if (ending.Check(data.UserMode == false))
	{
		end = clock();
		ending.ending(start, end);
	}

	return 0;
}