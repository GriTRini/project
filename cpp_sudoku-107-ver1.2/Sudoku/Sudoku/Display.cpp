#include "pch.h"
#include "Display.h"
#include <Windows.h>
#include <iostream>

using namespace std;

bool Display::Check(int data)
{
	if (data == 3)
		return true;
	return false;
}

void Display::ending(clock_t start, clock_t end)
{
	clock_t min = ((end - start) / CLOCKS_PER_SEC / 60) % 60;
	clock_t sec = (end - start) / CLOCKS_PER_SEC % 60;

	system("cls");

	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << "                                  소요 시간 : " << min % 60 << " 분  " << sec << " 초" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	cout << "                                         _         _ " << endl <<
		"                                        | |       | |" << endl <<
		"                         ____ _    _   _| | ____  | | ___  _   _" << endl <<
		"                        / ___| |  | |/ _  |/ __ ＼| |/  / | | | |" << endl <<
		"                        ＼__ ＼|__| | (_| || (_) ||   <   | |_| |" << endl <<
		"                        |____/＼____/＼___|＼____/|_|＼_＼＼____/" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << endl << "                               Designed by 'Team Bed Smell'" << endl
		<< "                                 Thank you for enjoying!!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	Sleep(5000);
}

void Display::shutdown()
{
	system("cls");

	cout << "   `dMMMMMN/    `sNMMMMN+``yNMMMMN+ `dMMMMNh. /hmmdmd/  /mMMMMMy`      -dMMMMMm- -NMMMMN+" << endl
		<< "   `mNMMMMm+    `oNMMMMN+ `yNMMMMm+ `hMMMMMNs.```.`.``  :mMMMMNh`      -dMMMMMm- :NMMMMm/  " << endl
		<< "   `mNMMMMN/     oNMMMMNo``yNMMMMNo `oNMMMMMNms-`       /NMMMMMh-..-.  .dMMMMMm/-sNMMMMm:  " << endl
		<< "   `dNMMMMm/    `sNMMMMNo``yMMMMMNo  .sNMMMMMMMNh/`     /mMMMMMMmNmmo` -dMMMMMMNmNMMMNds`  " << endl
		<< "   `mNMMMMN/    `sNMMMMNo `yNMMMMNo   `+mNMMMMMMMNh:`   /NMMMMMMMMMNo` -hNMMMMMMMMMMms-`   " << endl
		<< "   `dNMMMMm/    `sNMMMMN+``hNMMMMmo     ./hNMMMMMMNmo`  :NMMMMMMNNNmo  -dNMMMMNdhmMMMmh+   " << endl
		<< "   .mNMMMMN+    `oNMMMMN+``yNMMMMNo       `/hmMMMMMMm/  :NMMMMMd/::-.  .dNMMMMm:`+NMMMMd:  " << endl
		<< "   `dNMMMMN/    `sNMMMMNo `yMMMMMNo `--::::-`:hNMMMMNy` /mMMMMMd`      -dMMMMMm- -NMMMMm/  " << endl
		<< "   `mNMMMMm/    `sNMMMMNo `yNMMMMNo `yNNNNNh.`-dNMMMMh. /mMMMMMy`      -hMMMMMm- -mMMMMN+  " << endl
		<< "   `dNMMMMm/    `oNMMMMNo``hNMMMMm+ `yMMMMNh. .hMMMMNd. /NMMMMMy`      -dMMMMMm. -mMMMMN+  " << endl
		<< "   `mNMMMMNy/::-`/mMMMMNo``yNMMMMm/ `oNMMMNd. .hMMMMNh. :NMMMMMd/::--. .dNMMMMm- -mMMMMN+  " << endl
		<< "   `dMMMMMMMMNNh.:dMMMMNd+omMMMMNh.  +mMMMMNy/yNMMMMNy` +mMMMMMMNNNNd+ -dMMMMMm- -NMMMMN+  " << endl
		<< "   `mMMMMMMMMMMh.`/mNMMMMNMMMMMNd/   `smMMMMNNNMMMMNd/  /NMMMMMMMMMMm+ -hNMMMMm- -NMMMMN+  " << endl
		<< "   `hNNNNNNNNNNh`  :ymNNMMMMMNms-     .+hNNMMMMMNNdy-   /mNNNNNNNNNNm/ .dNNNNNd. -mNNNNm+  " << endl
		<< "   `://:::/:/::-`   `-/osyyso/-         `-+syyss+/.`    `:-::///:::/:. `-://:::` `::::/:.  " << endl
		<< endl << endl
		<< "                                sdhhhh+```ydh:``dd.``-ddhhhy/" << endl
		<< "                                yms---.```hmmd-`mm.``-mm:-/mm-" << endl
		<< "                                ymdss+````hmsmd-mm.``-mm-``mm/" << endl
		<< "                                ymy//:````hm//mhmm.``-mm-``mm/" << endl
		<< "                                ymy----```hm/`+mmm.``-mm/-+mm-`::-" << endl
		<< "                                ohhyyys```sh:``+hh.``.hhyyhs:``sh+" << endl;

	Sleep(5000);
}
