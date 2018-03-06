#pragma once
#include "Vector.h"
#include "include.h"

using namespace curse;

class Menu
{
protected:
	int _amountString;
	Vector<string> menu;
public:
	Menu()
	{
	}
	int ActivateMenu(int x, int y) //0 - выход или ошибка, от 1 до GetCount() - id menu, 999- Esc
	{
		if (menu.GetCount() == 0)
		{
			return 0;
		}
		int menuID = 0;
		int key = 0;
		while (menuID != menu.GetCount() - 1)
		{
			for (int i = 0; i < menu.GetCount(); i++)
			{
				if (i == menuID)
				{
					SetPosCurs(x + i, y);
					SetColor(0, 15);
					cout << menu[i];
					SetColor(15, 0);
				}
				else
				{
					SetPosCurs(x + i, y);
					cout << menu[i];
				}
			}
			while (key != 13)
			{
				key = _getch();
				if (key == 72)
				{
					if (menuID != 0)
					{
						menuID--;
					}
				}
				if (key == 80)
				{
					if (menuID != menu.GetCount()-1)
					{
						menuID++;
					}
				}
				if (key == 27)
				{
					return 999;
				}
				for (int i = 0; i < menu.GetCount(); i++)
				{
					if (i == menuID)
					{
						SetPosCurs(x + i, y);
						SetColor(0, 15);
						cout << menu[i];
						SetColor(15, 0);
					}
					else
					{
						SetPosCurs(x + i, y);
						cout << menu[i];
					}
				}
			}
			if (menuID+1 != menu.GetCount())
			{
				return menuID + 1;
			}
			else
			{
				return 0;
			}
		}
	}
	void AddButton(string name)
	{
		menu.Add(name);
	}
};
