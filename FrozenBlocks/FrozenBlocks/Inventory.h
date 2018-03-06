#pragma once
#include "include.h"
#include "Menu.h"
#include "Item.h"
using namespace curse;

class Inventory
{
protected:
	Item inv[3][6]; //[0][0] - шлем [1][0] - нагрудник [2][0] - поножи

	void PrintNameInInventory(Item obj)
	{
		string name = obj.GetName();
		int rarity = obj.GetRarity();

		switch (rarity)
		{
		case 0:
			SetColor(0, 15);
			if (name.size() > 11)
			{
				for (int i = 0; i < 11; i++)
				{
					cout << name[i];
				}
				cout << "...";
			}
			else
				cout << name;
			break;
		case 1:
			SetColor(2, 15);
			if (name.size() > 11)
			{
				for (int i = 0; i < 11; i++)
				{
					cout << name[i];
				}
				cout << "...";
			}
			else
				cout << name;
			break;
		case 2:
			SetColor(1, 15);
			if (name.size() > 11)
			{
				for (int i = 0; i < 11; i++)
				{
					cout << name[i];
				}
				cout << "...";
			}
			else
				cout << name;
			break;
		case 3:
			SetColor(5, 15);
			if (name.size() > 11)
			{
				for (int i = 0; i < 11; i++)
				{
					cout << name[i];
				}
				cout << "...";
			}
			else
				cout << name;
			break;
		case 4:
			SetColor(4, 15);
			if (name.size() > 11)
			{
				for (int i = 0; i < 11; i++)
				{
					cout << name[i];
				}
				cout << "...";
			}
			else
				cout << name;
			break;
		}
		SetColor(15, 0);
	}
	void PrintNameInInventory(Item obj, bool select)
	{
		string name = obj.GetName();
		int rarity = obj.GetRarity();
		
		if (select)
		{
			switch (rarity)
			{
			case 0:
				SetColor(0, 15);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 1:
				SetColor(2, 15);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 2:
				SetColor(1, 15);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 3:
				SetColor(5, 15);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 4:
				SetColor(4, 15);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			}
			SetColor(15, 0);
		}
		else
		{
			switch (rarity)
			{
			case 0:
				SetColor(15, 0);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 1:
				SetColor(2, 0);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 2:
				SetColor(1, 0);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 3:
				SetColor(5, 0);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			case 4:
				SetColor(4, 0);
				if (name.size() > 11)
				{
					for (int i = 0; i < 11; i++)
					{
						cout << name[i];
					}
					cout << "...";
				}
				else
					cout << name;
				break;
			}
			SetColor(15, 0);
		}
	}
	void ShowInv()
	{
		for (int j = 0; j < 26; j++)
		{
			SetPosCurs(3 + j, 6);
			for (int i = 0; i < 112; i++)
			{
				cout << " ";
			}
		}
		SetPosCurs(2, 6);
		cout << "Inventory " << ReturnCountBusySlots() << "/15: ";

		if (inv[0][0].GetBufArmor() != 0)
		{
			SetPosCurs(4, 22);
			cout << "Armor: ";
			SetPosCurs(5, 22);
			cout << "+" << inv[0][0].GetBufArmor();
		}
		inv[0][0].PrintIcon(4, 8);
		SetPosCurs(11, 8);
		if (inv[0][0].GetId() == 0)
		{
			cout << "            ";
		}
		else
		{
			switch (inv[0][0].GetRarity())
			{
			case 0:
				PrintNameInInventory(inv[0][0], false);
				break;
			case 1:
				SetColor(2, 0);
				PrintNameInInventory(inv[0][0], false);
				break;
			case 2:
				SetColor(1, 0);
				PrintNameInInventory(inv[0][0], false);
				break;
			case 3:
				SetColor(5, 0);
				PrintNameInInventory(inv[0][0], false);
				break;
			case 4:
				SetColor(14, 0);
				PrintNameInInventory(inv[0][0], false);
				break;
			}
			SetColor(15, 0);
		}
		if (inv[1][0].GetBufArmor() != 0)
		{
			SetPosCurs(12, 22);
			cout << "Armor: ";
			SetPosCurs(13, 22);
			cout << "+" << inv[1][0].GetBufArmor();
		}
		SetPosCurs(19, 8);
		inv[1][0].PrintIcon(12, 8);
		if (inv[1][0].GetId() == 0)
		{
			cout << "            ";
		}
		else
		{
			switch (inv[1][0].GetRarity())
			{
			case 0:
				PrintNameInInventory(inv[1][0], false);
				break;
			case 1:
				SetColor(2, 0);
				PrintNameInInventory(inv[1][0], false);
				(inv[1][0]);
				break;
			case 2:
				SetColor(1, 0);
				PrintNameInInventory(inv[1][0], false);
				break;
			case 3:
				SetColor(5, 0);
				PrintNameInInventory(inv[1][0], false);
				break;
			case 4:
				SetColor(14, 0);
				PrintNameInInventory(inv[1][0], false);
				break;
			}
			SetColor(15, 0);
		}
		if (inv[2][0].GetBufArmor() != 0)
		{
			SetPosCurs(20, 22);
			cout << "Armor: ";
			SetPosCurs(21, 22);
			cout << "+" << inv[2][0].GetBufArmor();
		}
		SetPosCurs(27, 8);
		inv[2][0].PrintIcon(20, 8);
		if (inv[2][0].GetId() == 0)
		{
			cout << "            ";
		}
		else
		{
			switch (inv[2][0].GetRarity())
			{
			case 0:
				PrintNameInInventory(inv[2][0], false);
				break;
			case 1:
				SetColor(2, 0);
				PrintNameInInventory(inv[2][0], false);
				break;
			case 2:
				SetColor(1, 0);
				PrintNameInInventory(inv[2][0], false);
				break;
			case 3:
				SetColor(5, 0);
				PrintNameInInventory(inv[2][0], false);
				break;
			case 4:
				SetColor(14, 0);
				PrintNameInInventory(inv[2][0], false);
				break;
			}
			SetColor(15, 0);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				SetPosCurs(11 + (i * 8), 27 + (j * 15));
				inv[i][j].PrintIcon(4 + (i * 8), 27 + (j * 15));
				if (inv[i][j].GetId() == 0)
				{
					cout << "            ";
				}
				else
				{
					switch (inv[i][j].GetRarity())
					{
					case 0:
						PrintNameInInventory(inv[i][j], false);
						break;
					case 1:
						SetColor(2, 0);
						PrintNameInInventory(inv[i][j], false);
						break;
					case 2:
						SetColor(1, 0);
						PrintNameInInventory(inv[i][j], false);
						break;
					case 3:
						SetColor(5, 0);
						PrintNameInInventory(inv[i][j], false);
						break;
					case 4:
						SetColor(14, 0);
						PrintNameInInventory(inv[i][j], false);
						break;
					}
					SetColor(15, 0);
				}
			}
		}
	}
	void SelectName(int invCordX, int invCordY, int oldx, int oldy)
	{
		SetPosCurs(11 + (invCordX * 8), 27 + (invCordY * 15));
		cout << "              ";
		SetPosCurs(11 + (invCordX * 8), 27 + (invCordY * 15));
		switch (inv[invCordX][invCordY].GetRarity())
		{
		case 0:
			SetColor(0, 15);
			if (inv[invCordX][invCordY].GetId() == 0)
			{
				cout << "              ";
			}
			else
			{
				PrintNameInInventory(inv[invCordX][invCordY], true);
			}
			break;
		case 1:
			SetColor(2, 15);
			if (inv[invCordX][invCordY].GetId() == 0)
			{
				cout << "              ";
			}
			else
			{
				PrintNameInInventory(inv[invCordX][invCordY], true);
			}
			break;
		case 2:
			SetColor(1, 15);
			if (inv[invCordX][invCordY].GetId() == 0)
			{
				cout << "              ";
			}
			else
			{
				PrintNameInInventory(inv[invCordX][invCordY], true);
			}
			break;
		case 3:
			SetColor(5, 15);
			if (inv[invCordX][invCordY].GetId() == 0)
			{
				cout << "              ";
			}
			else
			{
				PrintNameInInventory(inv[invCordX][invCordY], true);
			}
			break;
		case 4:
			SetColor(4, 15);
			if (inv[invCordX][invCordY].GetId() == 0)
			{
				cout << "              ";
			}
			else
			{
				PrintNameInInventory(inv[invCordX][invCordY], true);
			}
			break;
		}
		SetColor(15, 0);

		if (oldx + oldy != 0)
		{
			SetPosCurs(11 + (oldx * 8), 27 + (oldy * 15));

			if (inv[oldx][oldy].GetId() == 0)
			{
				cout << "              ";
			}
			else
			{
				PrintNameInInventory(inv[oldx][oldy], false);
			}
		}
	}
public:
	void AddItem(Item obj)
	{
		if (ReturnCountFreeSlots() != 0)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 1; j < 6; j++)
				{
					if (inv[i][j].GetId() == 0)
					{
						inv[i][j] = obj;
						return;
					}
				}
			}
		}
	}
	int ReturnCountFreeSlots() 
	{
		int free = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (inv[i][j].GetId() == 0)
				{
					free++;
				}
			}
		}
		return free;
	}
	int ReturnCountBusySlots()
	{
		int free = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (inv[i][j].GetId() != 0)
				{
					free++;
				}
			}
		}
		return free;
	}
	void OpenInv(Player *p1cpy, World *wcpy)
	{

		int invCordX = 0;
		int invCordY = 1;

		bool exit = false;

		ShowInv();

		SelectName(invCordX, invCordY, 0, 0);
		while (!exit)
		{
			if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0 || (GetKeyState(0x49) & 0x8000) != 0)
			{
				exit = true;
			}
			else if ((GetKeyState(VK_UP) & 0x8000) != 0)
			{
				Sleep(100);
				if (invCordX != 0)
				{
					invCordX--;
					SelectName(invCordX, invCordY, invCordX+1, invCordY);
				}
				
			}
			else if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
			{
				Sleep(100);
				if (invCordX != 2)
				{
					invCordX++;
					SelectName(invCordX, invCordY, invCordX-1, invCordY);
				}
				
			}
			else if ((GetKeyState(VK_RIGHT) & 0x8000) != 0)
			{
				Sleep(100);
				if (invCordY != 5)
				{
					invCordY++;
					SelectName(invCordX, invCordY, invCordX, invCordY-1);
				}
				
			}
			else if ((GetKeyState(VK_LEFT) & 0x8000) != 0)
			{
				Sleep(100);
				if (invCordY != 1)
				{
					invCordY--;
					SelectName(invCordX, invCordY, invCordX, invCordY+1);
				}
				
			}
			else if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
			{
				SetPosCurs(11 + (invCordX * 8), 27 + (invCordY * 15));
				inv[invCordX][invCordY].PrintIconEmpty(4 + (invCordX * 8), 27 + (invCordY * 15));
				int KEY = 0;
				int MID = 1;

				switch (inv[invCordX][invCordY].GetId())
				{
				case 1:
					if (true)
					{
						Sleep(100);
						MID = 1;
						bool exit = false;
						if (MID == 1)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							if (inv[invCordX][invCordY].GetIsUse())
							{
								cout << "Don't use";
							}
							else
							{
								cout << "Use";
							}
							SetColor(15, 0);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 2)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							if (inv[invCordX][invCordY].GetIsUse())
							{
								cout << "Don't use";
							}
							else
							{
								cout << "Use";
							}
							SetColor(0, 15);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetColor(15, 0);
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 3)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							if (inv[invCordX][invCordY].GetIsUse())
							{
								cout << "Don't use";
							}
							else
							{
								cout << "Use";
							}
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Drop";
							SetColor(15, 0);
						}
						while (!exit)
						{
							//MID = ItemMenu.ActivateMenu(5 + (invCordX * 8), 28 + (invCordY * 15));
							if ((GetKeyState(VK_UP) & 0x8000) != 0)
							{
								if (MID != 1)
								{
									MID--;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(250);
							}
							if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
							{
								if (MID != 3)
								{
									MID++;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(250);
							}
							if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0)
							{
								exit = true;
							}

							if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
							{
								if (MID == 1)
								{
									if (!inv[invCordX][invCordY].GetIsUse())
									{
										for (int i = 0; i < 3; i++)
										{
											for (int j = 1; j < 6; j++)
											{
												if (inv[i][j].GetId() == 1)
												{
													if (inv[i][j].GetIsUse())
													{
														inv[i][j].toggleIsUse(); //может использоваться только 1 меч
														p1cpy->SetNewSLAC(p1cpy->GetSLAC("strength") - inv[i][j].GetBufStrength(), p1cpy->GetSLAC("luck") - inv[i][j].GetBufLuck(), p1cpy->GetSLAC("agility") - inv[i][j].GetBufAgility(), p1cpy->GetSLAC("charisma") - inv[i][j].GetBufCharisma());
													}
												}
											}
										}
										p1cpy->SetNewSLAC(p1cpy->GetSLAC("strength") + inv[invCordX][invCordY].GetBufStrength(), p1cpy->GetSLAC("luck") + inv[invCordX][invCordY].GetBufLuck(), p1cpy->GetSLAC("agility") + inv[invCordX][invCordY].GetBufAgility(), p1cpy->GetSLAC("charisma") + inv[invCordX][invCordY].GetBufCharisma());
									}
									else
									{
										p1cpy->SetNewSLAC(p1cpy->GetSLAC("strength") - inv[invCordX][invCordY].GetBufStrength(), p1cpy->GetSLAC("luck") - inv[invCordX][invCordY].GetBufLuck(), p1cpy->GetSLAC("agility") - inv[invCordX][invCordY].GetBufAgility(), p1cpy->GetSLAC("charisma") - inv[invCordX][invCordY].GetBufCharisma());
									}
									Sleep(100);
									inv[invCordX][invCordY].toggleIsUse();
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "            ";
									SetPosCurs(35, 24);
									cout << "              ";
									SetPosCurs(35, 24);
									cout << "Strength" << p1cpy->GetSLAC("strength");
									SetPosCurs(34, 24);
									cout << "              ";
									SetPosCurs(34, 24);
									cout << "Luck" << p1cpy->GetSLAC("luck");
									SetPosCurs(35, 44);
									cout << "              ";
									SetPosCurs(35, 44);
									cout << "Agility" << p1cpy->GetSLAC("agility");
									SetPosCurs(34, 44);
									cout << "              ";
									SetPosCurs(34, 44);
									cout << "Charisma" << p1cpy->GetSLAC("charisma");
									if (MID == 1)
									{
										SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
										SetColor(0, 15);
										if (inv[invCordX][invCordY].GetIsUse())
										{
											cout << "Don't use";
										}
										else
										{
											cout << "Use";
										}
										SetColor(15, 0);
										SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "Discription";
										SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "Drop";
									}
									if (MID == 2)
									{
										SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
										if (inv[invCordX][invCordY].GetIsUse())
										{
											cout << "Don't use";
										}
										else
										{
											cout << "Use";
										}
										SetColor(0, 15);
										SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "Discription";
										SetColor(15, 0);
										SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "Drop";
									}
									if (MID == 3)
									{
										SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
										if (inv[invCordX][invCordY].GetIsUse())
										{
											cout << "Don't use";
										}
										else
										{
											cout << "Use";
										}
										SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "Discription";
										SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
										SetColor(0, 15);
										cout << "Drop";
										SetColor(15, 0);
									}
								}
								else if (MID == 2)
								{
									for (int i = 0; i < 5; i++)
									{
										SetPosCurs((5 + i) + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
									}
									int space = 0;
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufAgility() != 0)
									{
										cout << "Agility+" << inv[invCordX][invCordY].GetBufAgility();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufCharisma() != 0)
									{
										cout << "Charisma+" << inv[invCordX][invCordY].GetBufCharisma();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufLuck() != 0)
									{
										cout << "Luck+" << inv[invCordX][invCordY].GetBufLuck();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufStrength() != 0)
									{
										cout << "Strength+" << inv[invCordX][invCordY].GetBufStrength();
										space++;
									}
									while ((GetKeyState(VK_ESCAPE) & 0x8000) == 0) {}
								}
								else if (MID == 3)
								{

									if (inv[invCordX][invCordY].GetIsUse())
									{
										p1cpy->SetNewSLAC(p1cpy->GetSLAC("strength") - inv[invCordX][invCordY].GetBufStrength(), p1cpy->GetSLAC("luck") - inv[invCordX][invCordY].GetBufLuck(), p1cpy->GetSLAC("agility") - inv[invCordX][invCordY].GetBufAgility(), p1cpy->GetSLAC("charisma") - inv[invCordX][invCordY].GetBufCharisma());
										SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
										SetPosCurs(35, 24);
										cout << "              ";
										SetPosCurs(35, 24);
										cout << "Strength" << p1cpy->GetSLAC("strength");
										SetPosCurs(34, 24);
										cout << "              ";
										SetPosCurs(34, 24);
										cout << "Luck" << p1cpy->GetSLAC("luck");
										SetPosCurs(35, 44);
										cout << "              ";
										SetPosCurs(35, 44);
										cout << "Agility" << p1cpy->GetSLAC("agility");
										SetPosCurs(34, 44);
										cout << "              ";
										SetPosCurs(34, 44);
										cout << "Charisma" << p1cpy->GetSLAC("charisma");
									}

									wcpy->AddDropToBlock(inv[invCordX][invCordY], p1cpy->GetPosX(), p1cpy->GetPosY());
									inv[invCordX][invCordY] = Item();
									
									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[0][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
								}
							}
						}
					}
					break;
				case 2:
					if (!inv[invCordX][invCordY].GetIsUse())
					{
						Sleep(100);

						GetSIDItem(invCordX, invCordY);

						MID = 1;
						bool exit = false;
						if (MID == 1)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Use";
							SetColor(15, 0);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 2)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Use";
							SetColor(0, 15);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetColor(15, 0);
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 3)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Use";
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Drop";
							SetColor(15, 0);
						}
						while (!exit)
						{
							//MID = ItemMenu.ActivateMenu(5 + (invCordX * 8), 28 + (invCordY * 15));
							if ((GetKeyState(VK_UP) & 0x8000) != 0)
							{
								if (MID != 1)
								{
									MID--;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Use";
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(100);
							}
							if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
							{
								if (MID != 3)
								{
									MID++;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Use";
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(100);
							}
							if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0)
							{
								exit = true;
							}

							if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
							{
								if (MID == 1)
								{
									if (inv[0][0].GetIsUse())
									{
										inv[0][0].toggleIsUse();
									}
									inv[invCordX][invCordY].toggleIsUse();

									Item obj = inv[0][0];
									inv[0][0] = inv[invCordX][invCordY];
									inv[invCordX][invCordY] = obj;

									p1cpy->SetMaxArmor(p1cpy->GetMaxArmor() + inv[0][0].GetBufArmor());
									p1cpy->GiveArmor(inv[0][0].GetBufArmor());

									SetPosCurs(37, 4);
									cout << "[";
									int cub = GetPercent(p1cpy->GetMaxArmor(), p1cpy->GetArmor()) * 55;
									for (int i = 0; i < 55; i++)
									{
										if (cub < i)
										{
											cout << " ";
										}
										else
										{
											SetColor(1, 0);
											cout << (char)254;
											SetColor(15, 0);
										}
									}
									cout << "]";

									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[0][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
									inv[0][0].PrintIcon(4, 8);
								}
								else if (MID == 2)
								{
									for (int i = 0; i < 5;i++)
									{
										SetPosCurs((5+i) + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
									}

									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Armor:";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "+" << inv[invCordX][invCordY].GetBufArmor();

									while ((GetKeyState(VK_ESCAPE) & 0x8000) == 0) {}
								}
								else if (MID == 3)
								{
									wcpy->AddDropToBlock(inv[invCordX][invCordY], p1cpy->GetPosX(), p1cpy->GetPosY());
									inv[invCordX][invCordY] = Item();

									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[0][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
								}
							}
						}
					}
					break;
				case 3:
					if (!inv[invCordX][invCordY].GetIsUse())
					{
						Sleep(100);
						MID = 1;
						bool exit = false;
						if (MID == 1)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Use";
							SetColor(15, 0);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 2)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Use";
							SetColor(0, 15);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetColor(15, 0);
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 3)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Use";
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Drop";
							SetColor(15, 0);
						}
						while (!exit)
						{
							//MID = ItemMenu.ActivateMenu(5 + (invCordX * 8), 28 + (invCordY * 15));
							if ((GetKeyState(VK_UP) & 0x8000) != 0)
							{
								if (MID != 1)
								{
									MID--;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Use";
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(100);
							}
							if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
							{
								if (MID != 3)
								{
									MID++;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Use";
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(100);
							}
							if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0)
							{
								exit = true;
							}

							if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
							{
								if (MID == 1)
								{
									if (inv[1][0].GetIsUse())
									{
										inv[1][0].toggleIsUse();
									}
									inv[invCordX][invCordY].toggleIsUse();

									Item obj = inv[1][0];
									inv[1][0] = inv[invCordX][invCordY];
									inv[invCordX][invCordY] = obj;

									p1cpy->SetMaxArmor(p1cpy->GetMaxArmor() + inv[1][0].GetBufArmor());
									p1cpy->GiveArmor(inv[1][0].GetBufArmor());

									SetPosCurs(37, 4);
									cout << "[";
									int cub = GetPercent(p1cpy->GetMaxArmor(), p1cpy->GetArmor()) * 55;
									for (int i = 0; i < 55; i++)
									{
										if (cub < i)
										{
											cout << " ";
										}
										else
										{
											SetColor(1, 0);
											cout << (char)254;
											SetColor(15, 0);
										}
									}
									cout << "]";

									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[1][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
									inv[1][0].PrintIcon(12, 8);

									exit = true;
								}
								else if (MID == 2)
								{
									for (int i = 0; i < 5;i++)
									{
										SetPosCurs((5 + i) + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
									}

									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Armor:";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "+" << inv[invCordX][invCordY].GetBufArmor();

									while ((GetKeyState(VK_ESCAPE) & 0x8000) == 0) {}
								}
								else if (MID == 3)
								{
									wcpy->AddDropToBlock(inv[invCordX][invCordY], p1cpy->GetPosX(), p1cpy->GetPosY());
									inv[invCordX][invCordY] = Item();

									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[1][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
								}
							}
						}
					}
					break;
				case 4:
					if (!inv[invCordX][invCordY].GetIsUse())
					{
						Sleep(100);
						MID = 1;
						bool exit = false;
						if (MID == 1)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Use";
							SetColor(15, 0);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 2)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Use";
							SetColor(0, 15);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetColor(15, 0);
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 3)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Use";
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Drop";
							SetColor(15, 0);
						}
						while (!exit)
						{
							if ((GetKeyState(VK_UP) & 0x8000) != 0)
							{
								if (MID != 1)
								{
									MID--;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Use";
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(100);
							}
							if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
							{
								if (MID != 3)
								{
									MID++;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Use";
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Use";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(100);
							}
							if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0)
							{
								exit = true;
							}

							if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
							{
								if (MID == 1)
								{
									if (inv[2][0].GetIsUse())
									{
										inv[2][0].toggleIsUse();
									}
									inv[invCordX][invCordY].toggleIsUse();

									Item obj = inv[2][0];
									inv[2][0] = inv[invCordX][invCordY];
									inv[invCordX][invCordY] = obj;

									p1cpy->SetMaxArmor(p1cpy->GetMaxArmor() + inv[2][0].GetBufArmor());
									p1cpy->GiveArmor(inv[2][0].GetBufArmor());

									SetPosCurs(37, 4);
									cout << "[";
									int cub = GetPercent(p1cpy->GetMaxArmor(), p1cpy->GetArmor()) * 55;
									for (int i = 0; i < 55; i++)
									{
										if (cub < i)
										{
											cout << " ";
										}
										else
										{
											SetColor(1, 0);
											cout << (char)254;
											SetColor(15, 0);
										}
									}
									cout << "]";

									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[2][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
									inv[2][0].PrintIcon(20, 8);
								}
								else if (MID == 2)
								{
									for (int i = 0; i < 5;i++)
									{
										SetPosCurs((5 + i) + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
									}

									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Armor:";
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "+" << inv[invCordX][invCordY].GetBufArmor();

									while ((GetKeyState(VK_ESCAPE) & 0x8000) == 0) {}
								}
								else if (MID == 3)
								{
									wcpy->AddDropToBlock(inv[invCordX][invCordY], p1cpy->GetPosX(), p1cpy->GetPosY());
									inv[invCordX][invCordY] = Item();

									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[2][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
								}
							}
						}
					}
					break;
				case 5:
					if (true)
					{
						Sleep(100);
						MID = 1;
						bool exit = false;
						if (MID == 1)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							if (inv[invCordX][invCordY].GetIsUse())
							{
								cout << "Don't use";
							}
							else
							{
								cout << "Use";
							}
							SetColor(15, 0);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 2)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							if (inv[invCordX][invCordY].GetIsUse())
							{
								cout << "Don't use";
							}
							else
							{
								cout << "Use";
							}
							SetColor(0, 15);
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetColor(15, 0);
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Drop";
						}
						if (MID == 3)
						{
							SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
							if (inv[invCordX][invCordY].GetIsUse())
							{
								cout << "Don't use";
							}
							else
							{
								cout << "Use";
							}
							SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
							cout << "Discription";
							SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
							SetColor(0, 15);
							cout << "Drop";
							SetColor(15, 0);
						}
						while (!exit)
						{
							//MID = ItemMenu.ActivateMenu(5 + (invCordX * 8), 28 + (invCordY * 15));
							if ((GetKeyState(VK_UP) & 0x8000) != 0)
							{
								if (MID != 1)
								{
									MID--;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(250);
							}
							if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
							{
								if (MID != 3)
								{
									MID++;
								}
								if (MID == 1)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(15, 0);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 2)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetColor(0, 15);
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetColor(15, 0);
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Drop";
								}
								if (MID == 3)
								{
									SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetIsUse())
									{
										cout << "Don't use";
									}
									else
									{
										cout << "Use";
									}
									SetPosCurs(6 + (invCordX * 8), 28 + (invCordY * 15));
									cout << "Discription";
									SetPosCurs(7 + (invCordX * 8), 28 + (invCordY * 15));
									SetColor(0, 15);
									cout << "Drop";
									SetColor(15, 0);
								}
								Sleep(250);
							}
							if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0)
							{
								exit = true;
							}

							if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
							{
								if (MID == 1)
								{
									p1cpy->GiveHP(p1cpy->GetMaxHP() * (inv[invCordX][invCordY].GetHeal() / 100));
									p1cpy->SetNewSLAC(p1cpy->GetSLAC("strength") + inv[invCordX][invCordY].GetBufStrength(), p1cpy->GetSLAC("luck") + inv[invCordX][invCordY].GetBufLuck(), p1cpy->GetSLAC("agility") + inv[invCordX][invCordY].GetBufAgility(), p1cpy->GetSLAC("charisma") + inv[invCordX][invCordY].GetBufCharisma());

									SetPosCurs(36, 4);
									cout << "[";
									int cub = GetPercent(p1cpy->GetMaxHP(), p1cpy->GetHP()) * 55;
									for (int i = 0; i < 55; i++)
									{
										if (cub < i)
										{
											cout << " ";
										}
										else
										{
											SetColor(12, 0);
											cout << (char)254;
											SetColor(15, 0);
										}
									}
									cout << "]";

									inv[invCordX][invCordY] = Item();
									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[0][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
								}
								else if (MID == 2)
								{
									for (int i = 0; i < 5; i++)
									{
										SetPosCurs((5 + i) + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
									}
									int space = 0;
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufAgility() != 0)
									{
										cout << "Agility+" << inv[invCordX][invCordY].GetBufAgility();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufCharisma() != 0)
									{
										cout << "Charisma+" << inv[invCordX][invCordY].GetBufCharisma();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufLuck() != 0)
									{
										cout << "Luck+" << inv[invCordX][invCordY].GetBufLuck();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetBufStrength() != 0)
									{
										cout << "Strength+" << inv[invCordX][invCordY].GetBufStrength();
										space++;
									}
									SetPosCurs((5 + space) + (invCordX * 8), 28 + (invCordY * 15));
									if (inv[invCordX][invCordY].GetHeal() != 0)
									{
										cout << "Heal+" << inv[invCordX][invCordY].GetHeal() << "%";
										space++;
									}
									while ((GetKeyState(VK_ESCAPE) & 0x8000) == 0) {}
								}
								else if (MID == 3)
								{
										SetPosCurs(5 + (invCordX * 8), 28 + (invCordY * 15));
										cout << "            ";
										SetPosCurs(35, 24);
										cout << "              ";
										SetPosCurs(35, 24);
										cout << "Strength" << p1cpy->GetSLAC("strength");
										SetPosCurs(34, 24);
										cout << "              ";
										SetPosCurs(34, 24);
										cout << "Luck" << p1cpy->GetSLAC("luck");
										SetPosCurs(35, 44);
										cout << "              ";
										SetPosCurs(35, 44);
										cout << "Agility" << p1cpy->GetSLAC("agility");
										SetPosCurs(34, 44);
										cout << "              ";
										SetPosCurs(34, 44);
										cout << "Charisma" << p1cpy->GetSLAC("charisma");

										wcpy->AddDropToBlock(inv[invCordX][invCordY], p1cpy->GetPosX(), p1cpy->GetPosY());
									inv[invCordX][invCordY] = Item();
									exit = true;
									ShowInv();
									SelectName(invCordX, invCordY, 0, 0);
									inv[0][0].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
								}
							}
						}
					}
					break;
				}
				SetPosCurs(11 + (invCordX * 8), 27 + (invCordY * 15));
				inv[invCordX][invCordY].PrintIcon(4 + (invCordX * 8), 27 + (invCordY * 15));
				
			}
			Sleep(100);
		}
	}
	string GetSIDItem(int x, int y)
	{
		return inv[x][y].GetSID();
	}
	Item GetItem(int x, int y)
	{
		return inv[x][y];
	}
	Item *GetAdressItem(int x, int y)
	{
		return &inv[x][y];
	}
	Item GetIteminVector(int id)
	{
		vector<Item> obj;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j < 6; j++)
			{ 
				if (inv[i][j] != Item())
					obj.push_back(inv[i][j]);
			}
		}
		for (int i = 0; i < (15 - obj.size()); i++)
		{
			obj.push_back(Item());
		}
		return obj[id];
	}
	void DeleteItemforVector(int id)
	{
		vector<Item> obj;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (inv[i][j] != Item())
					obj.push_back(inv[i][j]);
			}
		}
		for (int i = 0; i < 15; i++)
		{
			obj.push_back(Item());
		}
		obj[id] = Item();
		int iter = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				inv[i][j] = obj[iter];
				iter++;
			}
		}
	}
	void SetInv(Item invObj[3][6])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				inv[i][j] = invObj[i][j];
			}
		}
	}
	Item (&GetInv())[3][6] { return inv; }
	void DeleteItem(int x, int y)
	{
		inv[x][y] = Item();
	}
};