#pragma once
#include "Level.h"
#include "Player.h"
#include "Inventory.h"
#include "Account.h"
#include "Menu.h"
#include "AccountDataBase.h"

class GameScripts
{
protected:
	Player p1;
	World w1;
	Inventory invent;
	Account _user;
	AccountDataBase DB;
	vector<Enemy> enemyes;
	vector<Item> shop;

	bool IsInventoryOpen = false;

	void PrintBarHP()
	{
		SetPosCurs(36, 4);
		cout << "[";
		int cub = GetPercent(p1.GetMaxHP(), p1.GetHP()) * 55;
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
	}
	void PrintBarArmor()
	{
		SetPosCurs(37, 4);
		cout << "[";
		int cub = GetPercent(p1.GetMaxArmor(), p1.GetArmor()) * 55;
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
	}

	int GameManu()
	{
		bool exit = false;
		int ret = 1;
		for (int i = 0; i < 6; i++)
		{
			SetPosCurs(13 + i, 52);
			for (int j = 0; j < 24; j++)
			{
				cout << " ";
			}
		}
		SetPosCurs(13, 60);
		cout << "[PAUSE]";
		if (ret == 1)
		{
			SetPosCurs(15, 54);
			SetColor(0, 15);
			cout << "Resume";
			SetColor(15, 0);
			SetPosCurs(16, 54);
			cout << "Exit";
		}
		else if (ret == 2)
		{
			SetPosCurs(15, 54);
			cout << "Resume";
			SetPosCurs(16, 54);
			SetColor(15, 0);
			cout << "Exit";
			SetColor(0, 15);
		}
		//(15, 54);
		while (!exit)
		{
			if ((GetKeyState(VK_UP) & 0x8000) != 0)
			{
				ret = 1;

				if (ret == 1)
				{
					SetPosCurs(15, 54);
					SetColor(0, 15);
					cout << "Resume";
					SetColor(15, 0);
					SetPosCurs(16, 54);
					cout << "Exit";
				}
				else if (ret == 2)
				{
					SetPosCurs(15, 54);					
					cout << "Resume";					
					SetPosCurs(16, 54);
					SetColor(0, 15);
					cout << "Exit";
					SetColor(15, 0);
				}
			}
			if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
			{
				ret = 2;

				if (ret == 1)
				{
					SetPosCurs(15, 54);
					SetColor(0, 15);
					cout << "Resume";
					SetColor(15, 0);
					SetPosCurs(16, 54);
					cout << "Exit";
				}
				else if (ret == 2)
				{
					SetPosCurs(15, 54);
					cout << "Resume";
					SetPosCurs(16, 54);
					SetColor(0, 15);
					cout << "Exit";
					SetColor(15, 0);
				}
			}
			if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
			{
				switch (ret)
				{
				case 1:
					return ret;
					break;
				case 2:
					return ret;
					break;
				}
			}
		}
		
	}
	void CheckBlock()
	{
		switch (w1.GetBlockID(p1.GetPosX(), p1.GetPosY()))
		{
		case 4:
			p1.TakeMoney(1);
			w1.SetBlockID(p1.GetPosX(), p1.GetPosY(), 0);
			break;
		}
		
	}
	void CreateEnemy()
	{
		int value = 3 + rand() % 2;
		for (int i = 0; i < value; i++)
		{
			string name = "Warior";
			int x = rand() % 29;
			int y = 20 + rand() % 40;
			double dam = 30 + rand() % 30;
			dam = dam / 100;
			while (!w1.GetBlockColision(x, y))
			{
				x = rand() % 29;
				y = 20 + rand() % 40;
			}

			double damage = 10;
			for (int i = 0; i < p1.GetLevel(); i++)
			{
				damage = damage + (damage * 0.25);
			}
			int damagebuf = damage * 0.25;
			damage = damage + (rand() % damagebuf);

			double hp = 10;
			for (int i = 0; i < p1.GetLevel(); i++)
			{
				hp = hp + (hp * 0.25);
			}
			int hpbuf = hp * 0.25;
			hp = hp + (rand() % hpbuf);

			enemyes.push_back(Enemy(name, x, y, damage, hp));
		}
	}
	bool IsEnemyNear(int eX, int eY)
	{
		int pX = p1.GetPosX();
		int pY = p1.GetPosY();

		if (pX + 1 == eX && pY + 1 == eY)
		{
			return true;
		}
		else if (pX + 1 == eX && pY - 1 == eY)
		{
			return true;
		}
		else if (pX - 1 == eX && pY - 1 == eY)
		{
			return true;
		}
		else if (pX - 1 == eX && pY - 1 == eY)
		{
			return true;
		}
		else if (pX + 1 == eX && pY == eY)
		{
			return true;
		}
		else if (pX == eX && pY - 1 == eY)
		{
			return true;
		}
		else if (pX - 1 == eX && pY == eY)
		{
			return true;
		}
		else if (pX == eX && pY + 1 == eY)
		{
			return true;
		}
		else if (pX == eX && pY == eY)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int WalkEnemy()
	{
		srand(time(0));
		for (int i = 0; i < enemyes.size(); i++)
		{
			if (!enemyes.at(i).isDead())
			{
				if (IsEnemyNear(enemyes.at(i).GetPosX(), enemyes.at(i).GetPosY()))
				{
					int result = enemyes.at(i).PlayerVSEnemy(&p1, _user.GetuserName());
					if (result == 0)
					{
						return 1;
					}
					else
					{
						if (p1.GetArmor() < 0)
						{
							invent.DeleteItem(0, 0);
							invent.DeleteItem(1, 0);
							invent.DeleteItem(2, 0);
							p1.SetMaxArmor(0);
						}
						else if (p1.GetArmor() < (p1.GetMaxArmor() * 0.25))
						{
							p1.SetMaxArmor(p1.GetMaxArmor() - (invent.GetItem(0, 0).GetBufArmor() + invent.GetItem(2, 0).GetBufArmor()));
							if (p1.GetMaxArmor() < 0)
							{
								p1.SetMaxArmor(0);
							}
							invent.DeleteItem(0, 0);
							invent.DeleteItem(2, 0);						
						}
						else if (p1.GetArmor() < (p1.GetMaxArmor() * 0.50))
						{
							p1.SetMaxArmor(p1.GetMaxArmor() - invent.GetItem(0, 0).GetBufArmor());
							if (p1.GetMaxArmor() < 0)
							{
								p1.SetMaxArmor(0);
							}
							invent.DeleteItem(0, 0);
						}

						/*int genranitem = rand() % 99;
						if (genranitem < 50)
						{
							w1.AddDropToBlock(GenerateItem(5), p1.GetPosX(), p1.GetPosY());
						}
						if (genranitem < 20)
						{
							w1.AddDropToBlock(GenerateItem(1), p1.GetPosX(), p1.GetPosY());
						}
						if (genranitem < 5)
						{
							w1.AddDropToBlock(GenerateItem(2), p1.GetPosX(), p1.GetPosY());
							w1.AddDropToBlock(GenerateItem(3), p1.GetPosX(), p1.GetPosY());
							w1.AddDropToBlock(GenerateItem(4), p1.GetPosX(), p1.GetPosY());
						}*/
						w1.AddDropToBlock(GenerateRandomItem(), p1.GetPosX(), p1.GetPosY());
						w1.AddDropToBlock(GenerateRandomItem(), p1.GetPosX(), p1.GetPosY());
						w1.AddDropToBlock(GenerateRandomItem(), p1.GetPosX(), p1.GetPosY());



						ShowMap();
						p1.ShowPlayer();
						ShowPlayerStats();
					}
				}
				else
				{
					int x = enemyes.at(i).GetPosX();
					int y = enemyes.at(i).GetPosY();
					int playerVisibleX = x - p1.GetPosX();
					int playerVisibleY = y - p1.GetPosY();
					if (playerVisibleX < enemyes.at(i).GetvisibleRange() && playerVisibleY < enemyes.at(i).GetvisibleRange() && playerVisibleX > -enemyes.at(i).GetvisibleRange() && playerVisibleY > -enemyes.at(i).GetvisibleRange()) //видит
					{
						int playerPosX = p1.GetPosX();
						int playerPosY = p1.GetPosY();

						int choisewalkenemy = rand() % 99;
						if (choisewalkenemy < 50)
						{
							SetPosCurs(x + 1, (y * 2) + 2);
							w1.ShowBlockXY(x, y);
							if (playerPosX > x)
							{
								if (w1.GetBlockID(x + 1, y) == 0)
								{
									x++;
								}
							}
							else if (playerPosX < x)
							{
								if (w1.GetBlockID(x - 1, y) == 0)
								{
									x--;
								}
							}

							if (playerPosY > y)
							{
								if (w1.GetBlockID(x, y + 1) == 0)
								{
									y++;
								}
							}
							else if (playerPosY < y)
							{
								if (w1.GetBlockID(x, y - 1) == 0)
								{
									y--;
								}
							}
							enemyes.at(i).SetPos(x, y);
							enemyes.at(i).ShowEnemy();
						}
					}
					else // невидит
					{
						enemyes.at(i).ShowEnemy();
						int choisewalkenemy = rand() % 99;
						if (choisewalkenemy < 100)
						{
							bool exit = false;
							while (!exit)
							{
								int way = rand() % 4;
								switch (way)
								{
								case 0:
									if (w1.GetBlockID(x + 1, y) == 0)
									{
										SetPosCurs(x + 1, (y * 2) + 2);
										w1.ShowBlockXY(x, y);
										x++;
										enemyes.at(i).SetPos(x, y);
										enemyes.at(i).ShowEnemy();
										exit = true;
									}
									break;
								case 1:
									if (w1.GetBlockID(x - 1, y) == 0)
									{
										SetPosCurs(x + 1, (y * 2) + 2);
										w1.ShowBlockXY(x, y);
										x--;
										enemyes.at(i).SetPos(x, y);
										enemyes.at(i).ShowEnemy();
										exit = true;
									}
									break;
								case 2:
									if (w1.GetBlockID(x, y + 1) == 0)
									{
										SetPosCurs(x + 1, (y * 2) + 2);
										w1.ShowBlockXY(x, y);
										y++;
										enemyes.at(i).SetPos(x, y);
										enemyes.at(i).ShowEnemy();
										exit = true;
									}
									break;
								case 3:
									if (w1.GetBlockID(x, y - 1) == 0)
									{
										SetPosCurs(x + 1, (y * 2) + 2);
										w1.ShowBlockXY(x, y);
										y--;
										enemyes.at(i).SetPos(x, y);
										enemyes.at(i).ShowEnemy();
										exit = true;
									}
									break;
								}
							}
						}
					}
					enemyes.at(i).ShowEnemy();
				}
			}
		}
		return 0;
	}
	void OpenInvGround()
	{
		for (int i = 0; i < 26; i++)
		{
			SetPosCurs(3 + i, 4);
			for (int j = 0; j < 55; j++)
			{
				cout << " ";
			}
		}
		for (int i = 0; i < 26; i++)
		{
			SetPosCurs(3 + i, 65);
			for (int j = 0; j < 55; j++)
			{
				cout << " ";
			}
		}
		int space = 0;
		for (int k = 0; k < 3; k++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (invent.GetItem(k, j).GetName() != "<NoneNameItem>")
				{
					SetPosCurs(4 + space, 6);
					//cout << invent.GetItem(k, j).GetName();
					invent.GetItem(k, j).PrintName();
					space++;
				}
			}
		}
		space = 0;
		for (int i = 0; i < w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()); i++)
		{
			SetPosCurs(4 + space, 67);
			w1.GetItemFromBlock(i, p1.GetPosX(), p1.GetPosY()).PrintName();
			space++;
		}
		SetPosCurs(2, 4);
		cout << "Inventory " << invent.ReturnCountBusySlots() << "/15: ";
		
		bool exit = false;
		int invX = 0, invY = 0;
		int x = 4, y = 6;

		if (invent.ReturnCountBusySlots() == 0)
		{
			invY = 1;
			y = 67;

			SetPosCurs(x, y);
			SetColor(0, 15);
			w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).GetName();
			SetColor(15, 0);
		}
		else
		{
			SetPosCurs(x, y);
			SetColor(0, 15);
			cout << invent.GetIteminVector(invX).GetName();
			SetColor(15, 0);
		}
		Sleep(250);
		while (!exit) 
		{
			if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0 || (GetKeyState(0x49) & 0x8000) != 0)
			{
				exit = true;
			}
			if ((GetKeyState(VK_RIGHT) & 0x8000) != 0)
			{
				if (invY != 1)
				{
					if (w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()) != 0)
					{
						SetPosCurs(x, y);
						invent.GetIteminVector(invX).PrintName();

						if (invX > w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()) - 1)
						{
							invX = w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()) - 1;
							x = invX + 4;
						}

						invY = 1;
						y = 67;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).GetName();
						SetColor(15, 0);
						Sleep(100);
					}
				}
			}
			if ((GetKeyState(VK_LEFT) & 0x8000) != 0)
			{
				if (invY != 0)
				{
					if (invent.ReturnCountBusySlots() != 0)
					{
						SetPosCurs(x, y);
						w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).PrintName();

						if (invX > invent.ReturnCountBusySlots() - 1)
						{
							invX = invent.ReturnCountBusySlots() - 1;
							x = invX + 4;
						}

						invY = 0;
						y = 6;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
						Sleep(100);
					}
				}
			}
			if ((GetKeyState(VK_UP) & 0x8000) != 0)
			{
				if (invY == 0)
				{
					if (invX != 0)
					{
						SetPosCurs(x, y);
						invent.GetIteminVector(invX).PrintName();

						invX--;
						x--;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
					}
				}
				else
				{
					if (invX != 0)
					{
						SetPosCurs(x, y);
						w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).PrintName();

						invX--;
						x--;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).GetName();
						SetColor(15, 0);
					}
				}
				Sleep(100);
			}
			if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
			{
				if (invY == 0)
				{
					if (invX != invent.ReturnCountBusySlots() - 1)
					{
						SetPosCurs(x, y);
						invent.GetIteminVector(invX).PrintName();

						invX++;
						x++;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
					}
				}
				else
				{
					if (invX != w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()) - 1)
					{
						SetPosCurs(x, y);
						w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).PrintName();

						invX++;
						x++;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).GetName();
						SetColor(15, 0);
					}
				}
				Sleep(100);
			}
			if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
			{
				space = 0;
				for (int k = 0; k < 3; k++)
				{
					for (int j = 1; j < 6; j++)
					{
						if (invent.GetItem(k, j).GetName() != "<NoneNameItem>")
						{
							SetPosCurs(4 + space, 6);
							for (int c = 0; c < invent.GetItem(k, j).GetName().size(); c++)
							{
								cout << " ";
							}
							space++;
						}
					}
				}
				space = 0;
				for (int i = 0; i < w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()); i++)
				{
					SetPosCurs(4 + space, 67);
					for (int b = 0; b < w1.GetItemFromBlock(i, p1.GetPosX(), p1.GetPosY()).GetName().size(); b++)
					{
						cout << " ";
					}
					space++;
				}

				if (invY == 0)
				{
					w1.AddDropToBlock(invent.GetIteminVector(invX), p1.GetPosX(), p1.GetPosY());
					invent.DeleteItemforVector(invX);
					if (invX == 0)
					{
						invY = 1;
						y = 67;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).GetName();
						SetColor(15, 0);
					}
					else
					{
						invX--;
						x--;
					}
				}
				else
				{
					if (invent.ReturnCountFreeSlots() == 0)
					{
						SetPosCurs(15, 50);
						cout << "Inventory is overcrowded";
					}
					else
					{
						invent.AddItem(w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()));
						w1.DeleteDropFromBlock(invX, p1.GetPosX(), p1.GetPosY());
					}
					if (invX == 0)
					{
						invY = 0;
						y = 6;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
					}
					else
					{
						invX--;
						x--;
					}
				}

				space = 0;
				for (int k = 0; k < 3; k++)
				{
					for (int j = 1; j < 6; j++)
					{
						if (invent.GetItem(k, j).GetName() != "<NoneNameItem>")
						{
							SetPosCurs(4 + space, 6);
							invent.GetItem(k, j).PrintName();
							space++;
						}
					}
				}
				space = 0;
				for (int i = 0; i < w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()); i++)
				{
					SetPosCurs(4 + space, 67);
					w1.GetItemFromBlock(i, p1.GetPosX(), p1.GetPosY()).PrintName();
					space++;
				}

				if (invY == 0)
				{
						SetPosCurs(x, y);
						SetColor(0, 15);
						invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);				
				}
				else
				{
						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << w1.GetItemFromBlock(invX, p1.GetPosX(), p1.GetPosY()).GetName();
						SetColor(15, 0);		
				}
				SetPosCurs(2, 4);
				cout << "Inventory " << invent.ReturnCountBusySlots() << "/15: ";
				Sleep(250);
			}
		}
	}
	void OpenShop()
	{
		SetPosCurs(2, 4);
		for (int j = 0; j < 28; j++)
		{
			SetPosCurs(2 + j, 4);
			for (int i = 0; i < 116; i++)
			{
				cout << " ";
			}
		}



		SetPosCurs(8, 77);
		cout << "Stand:";
		int space = 0;
		for (int i = 0; i < shop.size(); i++)
		{
			SetPosCurs(9 + space, 80);
			shop[i].PrintName();
			space++;
		}

		SetPosCurs(8, 21);
		cout << "Inventory:";
		space = 0;
		for (int k = 0; k < 3; k++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (invent.GetItem(k, j).GetName() != "<NoneNameItem>")
				{
					SetPosCurs(9 + space, 26);
					invent.GetItem(k, j).PrintName();
					space++;
				}
			}
		}

		int invX = 0, invY = 0;
		int x = 9, y = 26;
		bool exit = false;
		if (invent.ReturnCountBusySlots() == 0)
		{
			invY = 1;
			y = 80;
			SetPosCurs(x, y);
			SetColor(0, 15);
			cout << shop[invX].GetName();
			SetColor(15, 0);
		}
		else
		{
			SetPosCurs(x, y);
			SetColor(0, 15);
			cout << invent.GetIteminVector(invX).GetName();
			SetColor(15, 0);
		}
		while (!exit)
		{
			if ((GetKeyState(VK_RIGHT) & 0x8000) != 0)
			{
				if (invY != 1)
				{
					if (shop.size() != 0)
					{
						SetPosCurs(x, y);
						invent.GetIteminVector(invX).PrintName();

						if (invX > shop.size() - 1)
						{
							invX = shop.size() - 1;
							x = invX + 9;
						}

						invY = 1;
						y = 80;

						for (int i = 0; i < shop[invX].GetAmountBuf(); i++)
						{					
							int space = 0;
							if (shop[invX].GetBufAgility() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Agility + " << shop[invX].GetBufAgility();
								space++;
							}
							if (shop[invX].GetBufStrength() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Strength + " << shop[invX].GetBufStrength();
								space++;
							}
							if (shop[invX].GetBufLuck() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Luck + " << shop[invX].GetBufLuck();
								space++;
							}
							if (shop[invX].GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Charisma + " << shop[invX].GetBufCharisma();
								space++;
							}
							if (shop[invX].GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Charisma + " << shop[invX].GetBufCharisma();
								space++;
							}
							if (shop[invX].GetBufArmor() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Armor + " << shop[invX].GetBufArmor();
								space++;
							}
							if (shop[invX].GetHeal() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Heal + " << shop[invX].GetHeal();
								space++;
							}
							if (i == shop[invX].GetAmountBuf() - 1)
							{
								SetPosCurs(10 + space, 100);
								cout << "Cost: " << shop[invX].GetCostItem();
							}
						}

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << shop[invX].GetName();
						SetColor(15, 0);
						Sleep(100);
					}
				}
			}
			if ((GetKeyState(VK_LEFT) & 0x8000) != 0)
			{
				if (invY != 0)
				{
					if (invent.ReturnCountBusySlots() != 0)
					{
						SetPosCurs(x, y);
						shop[invX].PrintName();

						if (invX > invent.ReturnCountBusySlots() - 1)
						{
							invX = invent.ReturnCountBusySlots() - 1;
							x = invX + 9;
						}

						invY = 0;
						y = 26;

						for (int i = 0; i < invent.GetIteminVector(invX).GetAmountBuf(); i++)
						{
							int space = 0;
							if (invent.GetIteminVector(invX).GetBufAgility() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Agility + " << invent.GetIteminVector(invX).GetBufAgility();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufStrength() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Strength + " << invent.GetIteminVector(invX).GetBufStrength();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufLuck() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Luck + " << invent.GetIteminVector(invX).GetBufLuck();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Charisma + " << invent.GetIteminVector(invX).GetBufCharisma();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Charisma + " << invent.GetIteminVector(invX).GetBufCharisma();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufArmor() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Armor + " << invent.GetIteminVector(invX).GetBufArmor();
								space++;
							}
							if (invent.GetIteminVector(invX).GetHeal() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Heal + " << invent.GetIteminVector(invX).GetHeal();
								space++;
							}
							if (i == invent.GetIteminVector(invX).GetAmountBuf() - 1)
							{
								SetPosCurs(10 + space, 4);
								cout << "Cost: " << invent.GetIteminVector(invX).GetCostItem()/2;
							}
						}

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
						Sleep(100);
					}
				}
			}
			if ((GetKeyState(VK_UP) & 0x8000) != 0)
			{
				if (invY == 0)
				{
					if (invX != 0)
					{
						SetPosCurs(x, y);
						invent.GetIteminVector(invX).PrintName();
						for (int i = 0; i < invent.GetIteminVector(invX).GetAmountBuf() + 3; i++)
						{
							SetPosCurs(8 + i, 4);
							cout << "                 ";
						}
						invX--;
						x--;
						for (int i = 0; i < invent.GetIteminVector(invX).GetAmountBuf(); i++)
						{
							int space = 0;
							if (invent.GetIteminVector(invX).GetBufAgility() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Agility + " << invent.GetIteminVector(invX).GetBufAgility();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufStrength() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Strength + " << invent.GetIteminVector(invX).GetBufStrength();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufLuck() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Luck + " << invent.GetIteminVector(invX).GetBufLuck();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Charisma + " << invent.GetIteminVector(invX).GetBufCharisma();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Charisma + " << invent.GetIteminVector(invX).GetBufCharisma();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufArmor() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Armor + " << invent.GetIteminVector(invX).GetBufArmor();
								space++;
							}
							if (invent.GetIteminVector(invX).GetHeal() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Heal + " << invent.GetIteminVector(invX).GetHeal();
								space++;
							}
							if (i == invent.GetIteminVector(invX).GetAmountBuf() - 1)
							{
								SetPosCurs(10 + space, 4);
								cout << "Cost: " << invent.GetIteminVector(invX).GetCostItem()/2;
							}
						}
						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
					}
				}
				else
				{
					if (invX != 0)
					{
						SetPosCurs(x, y);
						shop[invX].PrintName();
						for (int i = 0; i < shop[invX].GetAmountBuf() + 3; i++)
						{
							SetPosCurs(8 + i, 100);
							cout << "                 ";
						}
						invX--;
						x--;
						for (int i = 0; i < shop[invX].GetAmountBuf(); i++)
						{
							int space = 0;
							if (shop[invX].GetBufAgility() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Agility + " << shop[invX].GetBufAgility();
								space++;
							}
							if (shop[invX].GetBufStrength() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Strength + " << shop[invX].GetBufStrength();
								space++;
							}
							if (shop[invX].GetBufLuck() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Luck + " << shop[invX].GetBufLuck();
								space++;
							}
							if (shop[invX].GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Charisma + " << shop[invX].GetBufCharisma();
								space++;
							}
							if (shop[invX].GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Charisma + " << shop[invX].GetBufCharisma();
								space++;
							}
							if (shop[invX].GetBufArmor() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Armor + " << shop[invX].GetBufArmor();
								space++;
							}
							if (shop[invX].GetHeal() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Heal + " << shop[invX].GetHeal();
								space++;
							}
							if (i == shop[invX].GetAmountBuf() - 1)
							{
								SetPosCurs(10 + space, 100);
								cout << "Cost: " << shop[invX].GetCostItem();
							}
						}
						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << shop[invX].GetName();
						SetColor(15, 0);
					}
				}
				Sleep(100);
			}
			if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
			{
				if (invY == 0)
				{
					if (invX != invent.ReturnCountBusySlots() - 1)
					{
						SetPosCurs(x, y);
						invent.GetIteminVector(invX).PrintName();
						for (int i = 0; i < invent.GetIteminVector(invX).GetAmountBuf() + 3; i++)
						{
							SetPosCurs(8 + i, 4);
							cout << "                 ";
						}
						invX++;
						x++;
						for (int i = 0; i < invent.GetIteminVector(invX).GetAmountBuf(); i++)
						{
							int space = 0;
							if (invent.GetIteminVector(invX).GetBufAgility() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Agility + " << invent.GetIteminVector(invX).GetBufAgility();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufStrength() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Strength + " << invent.GetIteminVector(invX).GetBufStrength();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufLuck() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Luck + " << invent.GetIteminVector(invX).GetBufLuck();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Charisma + " << invent.GetIteminVector(invX).GetBufCharisma();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Charisma + " << invent.GetIteminVector(invX).GetBufCharisma();
								space++;
							}
							if (invent.GetIteminVector(invX).GetBufArmor() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Armor + " << invent.GetIteminVector(invX).GetBufArmor();
								space++;
							}
							if (invent.GetIteminVector(invX).GetHeal() > 0)
							{
								SetPosCurs(8 + space, 4);
								cout << "Heal + " << invent.GetIteminVector(invX).GetHeal();
								space++;
							}
							if (i == invent.GetIteminVector(invX).GetAmountBuf() - 1)
							{
								SetPosCurs(10 + space, 4);
								cout << "Cost: " << invent.GetIteminVector(invX).GetCostItem()/2;
							}
						}
						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
					}
				}
				else
				{
					if (invX != shop.size() - 1)
					{
						SetPosCurs(x, y);
						shop[invX].PrintName();
						for (int i = 0; i < shop[invX].GetAmountBuf() + 3; i++)
						{
							SetPosCurs(8 + i, 100);
							cout << "                ";
						}
						invX++;
						x++;
						for (int i = 0; i < shop[invX].GetAmountBuf(); i++)
						{
							int space = 0;
							if (shop[invX].GetBufAgility() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Agility + " << shop[invX].GetBufAgility();
								space++;
							}
							if (shop[invX].GetBufStrength() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Strength + " << shop[invX].GetBufStrength();
								space++;
							}
							if (shop[invX].GetBufLuck() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Luck + " << shop[invX].GetBufLuck();
								space++;
							}
							if (shop[invX].GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Charisma + " << shop[invX].GetBufCharisma();
								space++;
							}
							if (shop[invX].GetBufCharisma() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Charisma + " << shop[invX].GetBufCharisma();
								space++;
							}
							if (shop[invX].GetBufArmor() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Armor + " << shop[invX].GetBufArmor();
								space++;
							}
							if (shop[invX].GetHeal() > 0)
							{
								SetPosCurs(8 + space, 100);
								cout << "Heal + " << shop[invX].GetHeal();
								space++;
							}
							if (i == shop[invX].GetAmountBuf() - 1)
							{
								SetPosCurs(10 + space, 100);
								cout << "Cost: " << shop[invX].GetCostItem();
							}
						}
						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << shop[invX].GetName();
						SetColor(15, 0);
					}
				}
				Sleep(100);
			}
			if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
			{
				SetPosCurs(15, 50);
				cout << "                            ";
				SetPosCurs(29, 6);
				cout << "                   ";
				space = 0;
				for (int k = 0; k < 3; k++)
				{
					for (int j = 1; j < 6; j++)
					{
						if (invent.GetItem(k, j).GetName() != "<NoneNameItem>")
						{
							SetPosCurs(9 + space, 26);
							for (int c = 0; c < invent.GetItem(k, j).GetName().size(); c++)
							{
								cout << " ";
							}
							space++;
						}
					}
				}
				space = 0;
				for (int i = 0; i < shop.size(); i++)
				{
					SetPosCurs(9 + space, 80);
					for (int j = 0; j < shop[i].GetName().size(); j++)
					{
						cout << " ";
					}
					space++;
				}

				if (invY == 0)
				{
					if (shop.size() > 14)
					{
						SetPosCurs(15, 50);
						cout << "Shop is overcrowded";
					}
					else
					{
						p1.TakeMoney((invent.GetIteminVector(invX).GetCostItem() / 2));
						shop.push_back(invent.GetIteminVector(invX));
						invent.DeleteItemforVector(invX);					
						if (invX == 0)
						{
							invY = 1;
							y = 80;

							SetPosCurs(x, y);
							SetColor(0, 15);
							cout << shop[invX].GetName();
							SetColor(15, 0);
						}
						else
						{
							invX--;
							x--;
						}
					}
				}
				else
				{
					if (invent.ReturnCountFreeSlots() == 0)
					{
						SetPosCurs(15, 50);
						cout << "Inventory is overcrowded";
					}
					else
					{
						if (p1.GetMoney() - shop[invX].GetCostItem() > 0)
						{
							p1.TakeAwayMoney(shop[invX].GetCostItem());
							invent.AddItem(shop[invX]);
							shop.erase(shop.begin() + invX);							
							SetPosCurs(29, 6);
							cout << "                   ";
						}
						else
						{
							SetPosCurs(29, 6);
							cout << "Not enough money...";
						}
					}
					if (invX == 0)
					{
						invY = 0;
						y = 26;

						SetPosCurs(x, y);
						SetColor(0, 15);
						cout << invent.GetIteminVector(invX).GetName();
						SetColor(15, 0);
					}
					else
					{
						invX--;
						x--;
					}
				}

				SetPosCurs(8, 77);
				cout << "Stand:";
				int space = 0;
				for (int i = 0; i < shop.size(); i++)
				{
					SetPosCurs(9 + space, 80);
					shop[i].PrintName();
					space++;
				}

				SetPosCurs(8, 21);
				cout << "Inventory:";
				space = 0;
				for (int k = 0; k < 3; k++)
				{
					for (int j = 1; j < 6; j++)
					{
						if (invent.GetItem(k, j).GetName() != "<NoneNameItem>")
						{
							SetPosCurs(9 + space, 26);
							invent.GetItem(k, j).PrintName();
							space++;
						}
					}
				}
				Sleep(250);
			}

			if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0) 
			{ 
				exit = true; 
			}
		}
	}
public:
	GameScripts(Account user, AccountDataBase DataBase)
	{
		_user = user;
		p1.SetMaxArmor(user.GetMaxArmor());
		p1.TakeMoney(user.GetMoney());
		p1.SetNewSLAC(user.GetStrength(), user.GetLuck(), user.GetAgility(), user.GetCharisma());
		p1.SetMaxHP(user.GetMaxHP());
		p1.SetLevel(user.GetLevel());
		DB = DataBase;
		p1.GiveHP(0);
		p1.GiveHP(user.GetHP());
		p1.GiveArmor(0);
		p1.GiveArmor(user.GetArmor());
		invent.SetInv(user.GetInv());
		for (int i = 0; i < 3; i++)
		{
			if (invent.GetItem(i, 0).GetBufArmor() > 0)
			{
				p1.SetMaxArmor(p1.GetArmor() + invent.GetItem(i, 0).GetBufArmor());
				p1.GiveArmor(invent.GetItem(i, 0).GetBufArmor());
			}
		}
	}

	void GenerateMap() 
	{ 
		if ((p1.GetLevel() % 5) == 0)
		{
			w1 = World();
			w1.GenerateHub();
			for (int i = 0; i < 10; i++)
			{
				int med = 2 + rand() % 2;
				shop.push_back(GenerateRarityItem(med));
			}
			for (int i = 0; i < 3; i++)
			{
				shop.push_back(GenerateItem(5));
			}
		}
		else
		{
			w1 = World();
			CreateEnemy();
		}	
	}
	void ShowMap()
	{ 
		w1.CloseNewLevel();
		w1.ShowWorld(1, 2); 
	}
	int SpawnPlayer()
	{
		invent.GetSIDItem(0, 1);
		p1.SetPos(w1.GetSpawn(), 0);
		p1.ShowPlayer();
		CheckBlock();
		if (p1.GetLevel() == 1)
		{
			invent.AddItem(GenerateItem(1, 0));
			invent.AddItem(GenerateItem(2, 0));
			invent.AddItem(GenerateItem(3, 0));
			invent.AddItem(GenerateItem(4, 0));
		}
		
		while (w1.GetBlockID(p1.GetPosX(), p1.GetPosY()) != 3)
		{
			SetPosCurs(p1.GetPosX() + 1, (p1.GetPosY() * 2) + 2);
			w1.ShowBlockXY(p1.GetPosX(), p1.GetPosY());

			if ((GetKeyState(0x57) & 0x8000) != 0)// W
			{
				if (w1.GetBlockColision(p1.GetPosX() - 1, p1.GetPosY()))
				{
					p1.SetPos(p1.GetPosX() - 1, p1.GetPosY());
				}
				p1.SetIcon({ (char)1,'!' });
				CheckBlock();
			}
			if ((GetKeyState(0x41) & 0x8000) != 0)// A
			{
				if (w1.GetBlockColision(p1.GetPosX(), p1.GetPosY() - 1))
				{
					p1.SetPos(p1.GetPosX(), p1.GetPosY() - 1);
				}
				p1.SetIcon({ (char)1,'!' });
				CheckBlock();
			}
			if ((GetKeyState(0x53) & 0x8000) != 0)// S
			{
				if (w1.GetBlockColision(p1.GetPosX() + 1, p1.GetPosY()))
				{
					p1.SetPos(p1.GetPosX() + 1, p1.GetPosY());
				}
				p1.SetIcon({ (char)1,'!' });
				CheckBlock();
			}
			if ((GetKeyState(0x44) & 0x8000) != 0)// D
			{
				if (w1.GetBlockColision(p1.GetPosX(), p1.GetPosY() + 1))
				{
					p1.SetPos(p1.GetPosX(), p1.GetPosY() + 1);
				}
				p1.SetIcon({ (char)1,'!' });
				CheckBlock();
			}

			if (WalkEnemy() == 1)
			{
				system("cls");

				ifstream  iop("icon/you died.txt", ios_base::in);
				int x = 5, y = 20;
				char buf[255];
				while (!iop.eof())
				{
					SetPosCurs(x, y);
					iop.getline(buf, 255);
					int i = 0;
					while (buf[i] != '\0')
					{
						if (buf[i] == ' ')
						{
							cout << " ";
						}
						else
						{
							cout << (char)219;
						}
						i++;
					}
					x++;
				}
				iop.close();

				SetPosCurs(15, 50);
				cout << "Your Score: " << p1.GetLevel();
				SetPosCurs(31, 40);
				cout << "Press Enter to restart the game..";

				enemyes.clear();
				_user = Account(_user.GetuserName(), _user.GetuserPassword());
				p1 = Player();
				invent = Inventory();
				_user.SetAccount(_user.GetuserName(), _user.GetuserPassword(), p1.GetLevel(), p1.GetSLAC("strength"), p1.GetSLAC("luck"), p1.GetSLAC("agility"), p1.GetSLAC("charisma"), p1.GetMaxHP(), p1.GetMaxArmor(), p1.GetMoney(), p1.GetHP(), p1.GetArmor(), invent.GetInv());
				_user.SaveAccountToDataBase();

				bool exit = false;
				while (!exit)
				{
					if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
						exit = true;
				}
				system("cls");
				return 1;
			}
			p1.ShowPlayer();
			
			if ((GetKeyState(0x49) & 0x8000) != 0)// I
			{
				if (w1.GetBlockID(p1.GetPosX(), p1.GetPosY()) != 5)
				{
					Player *p1cpy = &p1;
					if (w1.GetCountDrop(p1.GetPosX(), p1.GetPosY()) == 0)
					{
						invent.OpenInv(p1cpy, &w1);
					}
					else
					{
						OpenInvGround();
					}
					ShowMap();
					p1.ShowPlayer();
				}
				else
				{
					OpenShop();
					ShowMap();
					p1.ShowPlayer();
				}
			}

			if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0) // Esc
			{
				int menuid = GameManu();
				if (menuid == 2)
				{
					return 0;
				}
				else
				{
					ShowMap();
					p1.ShowPlayer();
				}
			}

			int key = 0;
			for (int i = 0; i < enemyes.size(); i++)
			{
				if (enemyes.at(i).isDead())
				{
					key++;
				}
			}
			if (key == enemyes.size())
			{
				w1.OpenNewLevel();
				SetPosCurs(w1.GetExit() + 1, 120);
				w1.ShowBlockXY(w1.GetExit(), 59);
			}
			Sleep(100);
		}
		enemyes.clear();
		p1.LevelUp();
		_user.SetAccount(_user.GetuserName(), _user.GetuserPassword(), p1.GetLevel(), p1.GetSLAC("strength"), p1.GetSLAC("luck"), p1.GetSLAC("agility"), p1.GetSLAC("charisma"), p1.GetMaxHP(), p1.GetMaxArmor(), p1.GetMoney(), p1.GetHP(), p1.GetArmor(), invent.GetInv());
		_user.SaveAccountToDataBase();
		return 1;
	}
	void ShowPlayerStats()
	{
		for (int i = 0; i < 7; i++)
		{
			SetPosCurs(32 + i, 2);
			if (i == 0)
			{
				cout << (char)201;
				SetPosCurs(32 + i, 3);
				cout << "[";

				SetPosCurs(32 + i, 121);
				cout << (char)187;
				SetPosCurs(32 + i, 120);
				cout << "]";
			}
			else if (i == 6)
			{
				cout << (char)200;
				for (int j = 0; j < 118; j++)
				{
					cout << (char)205;
				}
				SetPosCurs(32 + i, 121);
				cout << (char)188;
			}
			else
			{
				cout << (char)186;
				SetPosCurs(32 + i, 121);
				cout << (char)186;
			}
		}
		SetPosCurs(32 , 56);
		cout << "Player Stats";
		SetPosCurs(35, 4);
		cout << "Level: " << p1.GetLevel();
		SetPosCurs(34, 4);
		cout << "Money: " << p1.GetMoney();
		PrintBarHP();
		PrintBarArmor();
		SetPosCurs(35, 24);
		cout << "Strength: " << p1.GetSLAC("strength");
		SetPosCurs(34, 24);
		cout << "Luck: " << p1.GetSLAC("luck");
		SetPosCurs(35, 44);
		cout << "Agility: " << p1.GetSLAC("agility");
		SetPosCurs(34, 44);
		cout << "Charisma: " << p1.GetSLAC("charisma");
	}
	Item GenerateRandomItem()
	{
		int med = 1 + rand() % 99;
		srand(time(0) + med);
		
		int ItemId = 1 + rand() % 5;
		int ItemRarityRand = 1 + rand() % 100;
		int ItemRarity;
		if (ItemRarityRand > 99 - p1.GetSLAC("luck"))
		{
			ItemRarity = 4;
		}
		else if (ItemRarityRand > 95 - p1.GetSLAC("luck"))
		{
			ItemRarity = 3;
		}
		else if (ItemRarityRand > 80 - p1.GetSLAC("luck"))
		{
			ItemRarity = 2;
		}
		else if (ItemRarityRand > 70 - p1.GetSLAC("luck"))
		{
			ItemRarity = 1;
		}
		else
		{
			ItemRarity = 0;
		}

		string name;

		int strength = 0;
		int luck = 0;
		int agility = 0;
		int charisma = 0;

		double addHP = 0;
		double maxArmor = 0;

		double heal = 0;

		switch (ItemRarity)
		{
		case 1:
			name += "Imimproved ";
			break;
		case 2:
			name += "Rare ";
			break;
		case 3:
			name += "Legendary ";
			break;
		case 4:
			name += "Prime ";
			break;
		}
		int buf;
		switch (ItemId)
		{
		case 1:
			name += "Swoard";
			strength = (p1.GetLevel() / 2 )+ ItemRarity;
			if (strength <= 0)
				strength = 1;
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 2:
			name += "Helmet";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 3:
			name += "Chestplate";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 4:
			name += "Leggings";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 5:
			name += "Potion";
			switch (ItemRarity)
			{
			case 0:
				heal = 20;
				break;
			case 1:
				heal = 35;
				break;
			case 2:
				heal = 60;
				break;
			case 3:
				heal = 85;
				break;
			case 4:
				heal = 100;
				break;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		}
		
	}
	Item GenerateItem(int id)
	{
		int med = 1 + rand() % 99;
		srand(time(0) + med);

		int ItemId = id;
		int ItemRarityRand = 1 + rand() % 100;
		int ItemRarity;
		if (ItemRarityRand > 99 - p1.GetSLAC("luck"))
		{
			ItemRarity = 4;
		}
		else if (ItemRarityRand > 95 - p1.GetSLAC("luck"))
		{
			ItemRarity = 3;
		}
		else if (ItemRarityRand > 80 - p1.GetSLAC("luck"))
		{
			ItemRarity = 2;
		}
		else if (ItemRarityRand > 70 - p1.GetSLAC("luck"))
		{
			ItemRarity = 1;
		}
		else
		{
			ItemRarity = 0;
		}

		string name;

		int strength = 0;
		int luck = 0;
		int agility = 0;
		int charisma = 0;

		double addHP = 0;
		double maxArmor = 0;

		double heal = 0;

		switch (ItemRarity)
		{
		case 1:
			name += "Imimproved ";
			break;
		case 2:
			name += "Rare ";
			break;
		case 3:
			name += "Legendary ";
			break;
		case 4:
			name += "Prime ";
			break;
		}
		int buf;
		switch (ItemId)
		{
		case 1:
			name += "Swoard";
			strength = (p1.GetLevel() / 2) + ItemRarity;
			if (strength <= 0)
				strength = 1;
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 2:
			name += "Helmet";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 3:
			name += "Chestplate";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 4:
			name += "Leggings";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 5:
			name += "Potion";
			switch (ItemRarity)
			{
			case 0:
				heal = 20;
				break;
			case 1:
				heal = 35;
				break;
			case 2:
				heal = 60;
				break;
			case 3:
				heal = 85;
				break;
			case 4:
				heal = 100;
				break;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		}

	}
	Item GenerateItem(int id, int rarity)
	{
		srand(time(0));
		int ItemId = id;
		int ItemRarity = rarity;

		string name;

		int strength = 0;
		int luck = 0;
		int agility = 0;
		int charisma = 0;

		double addHP = 0;
		double maxArmor = 0;

		double heal = 0;

		switch (ItemRarity)
		{
		case 1:
			name += "Imimproved ";
			break;
		case 2:
			name += "Rare ";
			break;
		case 3:
			name += "Legendary ";
			break;
		case 4:
			name += "Prime ";
			break;
		}
		int buf;
		switch (ItemId)
		{
		case 1:
			name += "Swoard";
			strength = (p1.GetLevel() / 2) + ItemRarity;
			if (strength <= 0)
				strength = 1;
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 2:
			name += "Helmet";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 3:
			name += "Chestplate";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 4:
			name += "Leggings";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 5:
			name += "Potion";
			switch (ItemRarity)
			{
			case 0:
				heal = 20;
				break;
			case 1:
				heal = 35;
				break;
			case 2:
				heal = 60;
				break;
			case 3:
				heal = 85;
				break;
			case 4:
				heal = 100;
				break;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		}

	}
	Item GenerateRarityItem(int rarity)
	{
		int med = 1 + rand() % 99;
		srand(time(0) + med);

		int ItemId = 1 + rand() % 5;
		int ItemRarity = rarity;

		string name;

		int strength = 0;
		int luck = 0;
		int agility = 0;
		int charisma = 0;

		double addHP = 0;
		double maxArmor = 0;

		double heal = 0;

		switch (ItemRarity)
		{
		case 1:
			name += "Imimproved ";
			break;
		case 2:
			name += "Rare ";
			break;
		case 3:
			name += "Legendary ";
			break;
		case 4:
			name += "Prime ";
			break;
		}
		int buf;
		switch (ItemId)
		{
		case 1:
			name += "Swoard";
			strength = (p1.GetLevel() / 2) + ItemRarity;
			if (strength <= 0)
				strength = 1;
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 2:
			name += "Helmet";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 3:
			name += "Chestplate";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 4:
			name += "Leggings";
			buf = p1.GetMaxHP() / 3;
			if (ItemRarity == 0)
			{
				maxArmor = buf * 0.75;
			}
			else
			{
				maxArmor = buf * ItemRarity;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		case 5:
			name += "Potion";
			switch (ItemRarity)
			{
			case 0:
				heal = 20;
				break;
			case 1:
				heal = 35;
				break;
			case 2:
				heal = 60;
				break;
			case 3:
				heal = 85;
				break;
			case 4:
				heal = 100;
				break;
			}
			return Item(name, ItemId, ItemRarity, strength, luck, agility, charisma, maxArmor, heal);
			break;
		}

	}
};
