#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include "Vector.h"


namespace curse
{
	using namespace std;
	void SetPosCurs(int x, int y)
	{
		COORD position = { y, x }; //ïîçèöèÿ x è y
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}

	void SetTitle()
	{
		char title[] = "Frozen Blocks";
		CharToOem(title, title);
		SetConsoleTitle(title);
	}

	BOOL ShowConsoleCursor(BOOL bShow)
	{
		CONSOLE_CURSOR_INFO cci;
		HANDLE hStdOut;
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE)
			return FALSE;
		if (!GetConsoleCursorInfo(hStdOut, &cci))
			return FALSE;
		cci.bVisible = bShow;
		if (!SetConsoleCursorInfo(hStdOut, &cci))
			return FALSE;
		return TRUE;
	}

	enum ConsoleColor {
		Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGrey, DarkGrey,
		LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};
	void SetColor(int text, int background)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}

	double GetPercent(double percent, double num)
	{
		return num/percent;
	}

	void PrintLogo(int x, int y)
	{
		string logo = "]]]]]].]]]]]...]]]]..]]]]]].]]]]]..]]..]].]]]]]..]]......]]]]...]]]]..]]..]]..]]]]\n]].....]]..]].]]..]]....]]..]].....]]].]].]]..]].]].....]]..]].]]..]].]].]]..]]\n]]]]...]]]]]..]]..]]...]]...]]]]...]].]]].]]]]]..]].....]]..]].]].....]]]]....]]]]\n]].....]]..]].]]..]]..]]....]].....]]..]].]]..]].]].....]]..]].]]..]].]].]]......]]\n]].....]]..]]..]]]]..]]]]]].]]]]]..]]..]].]]]]]..]]]]]]..]]]]...]]]]..]]..]]..]]]]\n";
		SetPosCurs(x, y);
		for (int i = 0; i < logo.size(); i++)
		{
			if (logo[i] == ']')
			{
				cout << (char)219;
			}
			else if (logo[i] == '.')
			{
				cout << " ";
			}
			else if (logo[i] == '\n')
			{
				
				SetPosCurs(++x, y);
			}
		}
	}

	string icon_empty = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186, 
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186, 
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186, 
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188};

	string icon_sword = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, '/', '\\', (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)179, (char)179, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)179, (char)179, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, '<', (char)215, (char)215, '>', (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)222, (char)221, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188 };

	string icon_helmet = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)218, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)191, (char)186,
		(char)186, (char)179, (char)218, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)191, (char)179, (char)186,
		(char)186, (char)192, (char)217, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)192, (char)217, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)186,
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188 };

	string icon_ñhestpiece = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)32, (char)218, (char)196, (char)191, (char)32, (char)32, (char)32, (char)32, (char)218, (char)196, (char)191, (char)32, (char)186,
		(char)186, (char)32, (char)179, (char)32, (char)192, (char)196, (char)196, (char)196, (char)196, (char)217, (char)32, (char)179, (char)32, (char)186,
		(char)186, (char)32, (char)179, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)179, (char)32, (char)186,
		(char)186, (char)32, (char)179, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)32, (char)179, (char)32, (char)186,
		(char)186, (char)32, (char)192, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)217, (char)32, (char)186,
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188 };

	string icon_leggings = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)32, (char)218, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)191, (char)32, (char)186,
		(char)186, (char)32, (char)179, (char)32, (char)218, (char)196, (char)196, (char)196, (char)196, (char)191, (char)32, (char)179, (char)32, (char)186,
		(char)186, (char)32, (char)179, (char)32, (char)179, (char)32, (char)32, (char)32, (char)32, (char)179, (char)32, (char)179, (char)32, (char)186,
		(char)186, (char)32, (char)179, (char)32, (char)179, (char)32, (char)32, (char)32, (char)32, (char)179, (char)32, (char)179, (char)32, (char)186,
		(char)186, (char)32, (char)192, (char)196, (char)217, (char)32, (char)32, (char)32, (char)32, (char)192, (char)196, (char)217, (char)32, (char)186,
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188 };

	string icon_potion = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)32, (char)32, (char)32, (char)32, (char)214, (char)196, (char)196, (char)183, (char)32, 'o', (char)248, '`', (char)186,
		(char)186, (char)32, (char)32, (char)201, (char)205, (char)202, (char)205, (char)205, (char)202, (char)205, (char)187, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)199, (char)196, (char)196, (char)196, (char)196, (char)196, (char)196, (char)182, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)186, (char)176, (char)176, (char)176, (char)176, (char)176, (char)176, (char)186, (char)32, (char)32, (char)186,
		(char)186, (char)32, (char)32, (char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188, (char)32, (char)32, (char)186,
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188 };

	string icon_item = { (char)201, (char)205, (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)205 , (char)187,
		(char)186, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)186,
		(char)186, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)186,
		(char)186, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)186,
		(char)186, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)186,
		(char)186, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)220, (char)223, (char)186,
		(char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188 };
}
using namespace curse;

