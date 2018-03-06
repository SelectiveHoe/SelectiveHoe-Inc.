#pragma once
#include "include.h"
#include "Player.h"
#include "Menu.h"
#include "Item.h"

class Block
{
protected:
	int _id = 0;
	string _icon = { (char)176,(char)176 };
	bool _colision; // true - на блок можно встать false - нельзя
	vector<Item> drop;
public:
	Block() {}

	string GetIcon() { return _icon; }
	void SetId(int id)
	{
		if (_id != id)
		{
			_id = id;
		}
		switch (_id)
		{
		case 0:
			_icon = { (char)32,(char)32 };
			_colision = true;
			break;
		case 1:
			_icon = { (char)219,(char)219 }; //219 - standart
			_colision = false;
			break;
		case 2:
			_icon = { (char)62,(char)62 };
			_colision = true;
			break;
		case 3:
			_icon = { (char)62,(char)62 };
			_colision = true;
			break;
		case 4:
			_icon = { (char)79,(char)248 };
			break;
		case 5:
			_icon = { 'S','P' };
			break;
		}
	}
	bool GetColision() { return _colision; }
	void ShowBlock()
	{
		if (drop.size() == 0)
		{
			switch (_id)
			{
			case 0:
				SetColor(0, 7);
				break;
			case 1:
				SetColor(8, 0);
				break;
			case 4:
				SetColor(14, 7);
				break;
			case 2:
				SetColor(9, 7);
				break;
			case 3:
				if (_colision)
				{
					SetColor(10, 7);
				}
				else
				{
					SetColor(12, 7);
				}
				break;
			case 5:
				SetColor(10, 7);
				break;
			default:
				SetColor(15, 0);
				break;
			}
			cout << _icon;
			SetColor(15, 0);
		}
		else
		{
			SetColor(0, 7);
			cout << (char)214 << (char)183;
			SetColor(15, 0);
		}
	}
	int GetId() { return _id; }
	void SetColisionTrue() { _colision = true; }
	void SetColisionFalse() { _colision = false; }

	int GetSizeDrop() { return drop.size(); }
	Item GetItem(int id) { return drop[id]; }
	void AddItem(Item obj) 
	{ 
		if (drop.size() != 14)
		{
			if (obj != Item())
			{
				drop.push_back(obj);
			}
		}
	}
	void DeleteDrop(int id) { drop.erase(drop.begin() + id); }
};

class Enemy
{
protected:
	int _posX;
	int _posY;
	bool _isDead = false;

	string _name;
	string _texture = { (char)1,'!' };

	int _visibleRange = 6;

	double _damage;
	double _hp;
public:
	Enemy(){}
	Enemy(string name, int x, int y, double damage, double hp) 
	{
		_name = name;
		_posX = x;
		_posY = y;
		_damage = damage;
		_hp = hp;
	}

	void SetPos(int x, int y)
	{
		_posX = x;
		_posY = y;
	}
	void SetVisibleRange(int range) { _visibleRange = range; }


	int GetPosX() { return _posX; }
	int GetPosY() { return _posY; }
	int GetvisibleRange() { return _visibleRange; }
	bool isDead() { return _isDead; }

	void HitHim(double damage) 
	{
		_hp = _hp - damage;
		if (_hp < 0)
		{
			_isDead = true;
		}
	}
	void ShowEnemy()
	{
		SetPosCurs(_posX + 1, (_posY * 2) + 2);
		SetColor(12, 7);
		cout << _texture;
		SetColor(15, 0);
	}

	int PlayerVSEnemy(Player *pl, string name)
	{
		system("cls");
		cout << " " << name;
		SetPosCurs(0, 123 - _name.size());
		cout << _name;
		srand(time(0));
		bool exit = false;


		//Menu fight;
		//fight.AddButton("Head");
		//fight.AddButton("Left Armor");
		//fight.AddButton("Right Armor");
		//fight.AddButton("Body");

		ifstream  ifs("icon/player.txt", ios_base::in);
		int x = 4, y = 2;
		char buf[255]="sdfg";
		while (!ifs.eof())
		{
			SetPosCurs(x, y);
			ifs.getline(buf, 255);
			cout << buf;
			x++;
		}
		ifs.close();

		ifstream  ifst("icon/enemy.txt", ios_base::in);
		x = 8, y = 94;
		while (!ifst.eof())
		{
			SetPosCurs(x, y);
			ifst.getline(buf, 255);
			cout << buf;
			x++;
		}
		ifst.close();

		int menuid;
		int block;
		int EmaxHP = _hp;
		int hit;
		int cub;
		while (!exit)
		{
			SetPosCurs(1, 0);
			cout << "[";
			cub = GetPercent(pl->GetMaxHP(), pl->GetHP()) * 55;
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

			SetPosCurs(2, 2);
			cout << "[";
			cub = GetPercent(pl->GetMaxArmor(), pl->GetArmor()) * 55;
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
			
			SetPosCurs(1, 67);
			cout << "[";
			cub = GetPercent(EmaxHP, _hp) * 55;
			for (int i = 55; i > 0; i--)
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

			hit = rand() % 3;
			block = rand() % 3;
			SetPosCurs(28, 106);
			SetColor(0, 15);
			cout << "Select target";
			SetPosCurs(28, 8);
			SetColor(15, 0);
			cout << "Select protection";
			//int menuid = fight.ActivateMenu(10, 100);
			int menuid = 1;

			SetPosCurs(10, 111);
			cout << "Head";

			SetPosCurs(16, 118);
			cout << "Right";
			SetPosCurs(17, 118);
			cout << "Armor";

			SetPosCurs(16, 103);
			cout << "Left";
			SetPosCurs(17, 103);
			cout << "Armor";

			SetPosCurs(15, 111);
			cout << "Body";



			SetPosCurs(10, 15);
			cout << "Head";

			SetPosCurs(16, 22);
			cout << "Right";
			SetPosCurs(17, 22);
			cout << "Armor";

			SetPosCurs(16, 6);
			cout << "Left";
			SetPosCurs(17, 6);
			cout << "Armor";

			SetPosCurs(15, 15);
			cout << "Body";

			switch (menuid)
			{
			case 1:
				SetColor(0, 15);
				SetPosCurs(10, 111);
				cout << "Head";
				SetColor(15, 0);
				break;
			case 2:
				SetColor(0, 15);
				SetPosCurs(16, 118);
				cout << "Right";
				SetPosCurs(17, 118);
				cout << "Armor";
				SetColor(15, 0);
				break;
			case 3:
				SetColor(0, 15);
				SetPosCurs(16, 103);
				cout << "Left";
				SetPosCurs(17, 103);
				cout << "Armor";
				SetColor(15, 0);
				break;
			case 0:
				SetColor(0, 15);
				SetPosCurs(15, 111);
				cout << "Body";
				SetColor(15, 0);
				break;
			}

			bool exit = false;
			while (!exit)
			{
				if ((GetKeyState(VK_UP) & 0x8000) != 0)
				{
					SetPosCurs(10, 111);
					cout << "Head";

					SetPosCurs(16, 118);
					cout << "Right";
					SetPosCurs(17, 118);
					cout << "Armor";

					SetPosCurs(16, 103);
					cout << "Left";
					SetPosCurs(17, 103);
					cout << "Armor";

					SetPosCurs(15, 111);
					cout << "Body";

					menuid = 1;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 111);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 118);
						cout << "Right";
						SetPosCurs(17, 118);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 103);
						cout << "Left";
						SetPosCurs(17, 103);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 111);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
				{
					SetPosCurs(10, 111);
					cout << "Head";

					SetPosCurs(16, 118);
					cout << "Right";
					SetPosCurs(17, 118);
					cout << "Armor";

					SetPosCurs(16, 103);
					cout << "Left";
					SetPosCurs(17, 103);
					cout << "Armor";

					SetPosCurs(15, 111);
					cout << "Body";

					menuid = 0;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 111);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 118);
						cout << "Right";
						SetPosCurs(17, 118);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 103);
						cout << "Left";
						SetPosCurs(17, 103);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 111);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_LEFT) & 0x8000) != 0)
				{
					SetPosCurs(10, 111);
					cout << "Head";

					SetPosCurs(16, 118);
					cout << "Right";
					SetPosCurs(17, 118);
					cout << "Armor";

					SetPosCurs(16, 103);
					cout << "Left";
					SetPosCurs(17, 103);
					cout << "Armor";

					SetPosCurs(15, 111);
					cout << "Body";

					menuid = 3;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 111);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 118);
						cout << "Right";
						SetPosCurs(17, 118);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 103);
						cout << "Left";
						SetPosCurs(17, 103);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 111);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_RIGHT) & 0x8000) != 0)
				{
					SetPosCurs(10, 111);
					cout << "Head";

					SetPosCurs(16, 118);
					cout << "Right";
					SetPosCurs(17, 118);
					cout << "Armor";

					SetPosCurs(16, 103);
					cout << "Left";
					SetPosCurs(17, 103);
					cout << "Armor";

					SetPosCurs(15, 111);
					cout << "Body";

					menuid = 2;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 111);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 118);
						cout << "Right";
						SetPosCurs(17, 118);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 103);
						cout << "Left";
						SetPosCurs(17, 103);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 111);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
				{
					exit = true;
					Sleep(250);
				}
			}

			SetPosCurs(5, 30);
			cout << "                               ";
			
			if (menuid == block)
			{
				ifstream  ifs("icon/shield.txt", ios_base::in);
				int x = 15, y = 88;
				char buf[255] = "sdfg";
				while (!ifs.eof())
				{
					SetPosCurs(x, y);
					ifs.getline(buf, 255);
					cout << buf;
					x++;
				}
				ifs.close();
			}
			else
			{
				x = 15;
				y = 88;
				for (int i = 0; i < 9; i++)
				{
					SetPosCurs(x, y);
					cout << "            ";
					x++;
				}
				switch (menuid)
				{
				case 1:
					_hp = _hp - (pl->GetDamage() * 1.1);
					SetPosCurs(5, 80);
					SetColor(13, 0);
					cout << '-' << pl->GetDamage() * 1.1;
					SetColor(15, 0);
					break;
				case 2:
					_hp = _hp - (pl->GetDamage() * 0.75);
					SetPosCurs(5, 80);
					SetColor(13, 0);
					cout << '-' << pl->GetDamage() * 1.1;
					SetColor(15, 0);
					break;
				case 3:
					_hp = _hp - (pl->GetDamage() * 0.75);
					SetPosCurs(5, 80);
					SetColor(13, 0);
					cout << '-' << pl->GetDamage() * 1.1;
					SetColor(15, 0);
					break;
				case 0:
					_hp = _hp - pl->GetDamage();
					SetPosCurs(5, 80);
					SetColor(13, 0);
					cout << '-' << pl->GetDamage() * 1.1;
					SetColor(15, 0);
					break;
				}
				SetColor(15, 0);
				SetPosCurs(31, 30);
				cout << "                                              ";
			}

			if (_hp < 0)
			{
				SetPosCurs(1, 67);
				cout << "[";
				cub = GetPercent(EmaxHP, _hp) * 55;
				for (int i = 55; i > 0; i--)
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

				ifstream  iop("icon/You won.txt", ios_base::in);
				x = 15, y = 10;
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

				Sleep(3000);
				pl->TakeMoney(5);
				_isDead = true;
				system("cls");
				return 1;
			}
			else
			{
				SetPosCurs(1, 67);
				cout << "[";
				cub = GetPercent(EmaxHP, _hp) * 55;
				for (int i = 55; i > 0; i--)
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
		

			Sleep(300);
			
			SetPosCurs(28, 106);
			cout << "Select target";
			SetPosCurs(28, 8);
			SetColor(0, 15);
			cout << "Select protection";
			SetColor(15, 0);

			//menuid = fight.ActivateMenu(10, 7);
			exit = false;
			while (!exit)
			{
				if ((GetKeyState(VK_UP) & 0x8000) != 0)
				{
					SetPosCurs(10, 15);
					cout << "Head";

					SetPosCurs(16, 22);
					cout << "Right";
					SetPosCurs(17, 22);
					cout << "Armor";

					SetPosCurs(16, 6);
					cout << "Left";
					SetPosCurs(17, 6);
					cout << "Armor";

					SetPosCurs(15, 15);
					cout << "Body";

					menuid = 1;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 15);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 22);
						cout << "Right";
						SetPosCurs(17, 22);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 6);
						cout << "Left";
						SetPosCurs(17, 6);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 15);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_DOWN) & 0x8000) != 0)
				{
					SetPosCurs(10, 15);
					cout << "Head";

					SetPosCurs(16, 22);
					cout << "Right";
					SetPosCurs(17, 22);
					cout << "Armor";

					SetPosCurs(16, 6);
					cout << "Left";
					SetPosCurs(17, 6);
					cout << "Armor";

					SetPosCurs(15, 15);
					cout << "Body";

					menuid = 0;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 15);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 22);
						cout << "Right";
						SetPosCurs(17, 22);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 6);
						cout << "Left";
						SetPosCurs(17, 6);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 15);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_LEFT) & 0x8000) != 0)
				{
					SetPosCurs(10, 15);
					cout << "Head";

					SetPosCurs(16, 22);
					cout << "Right";
					SetPosCurs(17, 22);
					cout << "Armor";

					SetPosCurs(16, 6);
					cout << "Left";
					SetPosCurs(17, 6);
					cout << "Armor";

					SetPosCurs(15, 15);
					cout << "Body";

					menuid = 3;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 15);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 22);
						cout << "Right";
						SetPosCurs(17, 22);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 6);
						cout << "Left";
						SetPosCurs(17, 6);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 15);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}
				if ((GetKeyState(VK_RIGHT) & 0x8000) != 0)
				{
					SetPosCurs(10, 15);
					cout << "Head";

					SetPosCurs(16, 22);
					cout << "Right";
					SetPosCurs(17, 22);
					cout << "Armor";

					SetPosCurs(16, 6);
					cout << "Left";
					SetPosCurs(17, 6);
					cout << "Armor";

					SetPosCurs(15, 15);
					cout << "Body";

					menuid = 2;

					switch (menuid)
					{
					case 1:
						SetColor(0, 15);
						SetPosCurs(10, 15);
						cout << "Head";
						SetColor(15, 0);
						break;
					case 2:
						SetColor(0, 15);
						SetPosCurs(16, 22);
						cout << "Right";
						SetPosCurs(17, 22);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 3:
						SetColor(0, 15);
						SetPosCurs(16, 6);
						cout << "Left";
						SetPosCurs(17, 6);
						cout << "Armor";
						SetColor(15, 0);
						break;
					case 0:
						SetColor(0, 15);
						SetPosCurs(15, 15);
						cout << "Body";
						SetColor(15, 0);
						break;
					}
					Sleep(250);
				}

				if ((GetKeyState(VK_RETURN) & 0x8000) != 0)
				{
					exit = true;
					Sleep(250);
				}
			}
			exit = false;

			hit = rand() % 3;
			if (hit == menuid)
			{
				ifstream  ifsf("icon/shield.txt", ios_base::in);
				int x = 15, y = 28;
				char buf[255];
				while (!ifsf.eof())
				{
					SetPosCurs(x, y);
					ifsf.getline(buf, 255);
					cout << buf;
					x++;
				}
				ifsf.close();
			}
			else
			{
				x = 15;
				y = 28;
				for (int i = 0; i < 9; i++)
				{
					SetPosCurs(x, y);
					cout << "            ";
					x++;
				}
				switch (hit)
				{
				case 1:
					_damage = _damage * 1.1;
					pl->TakeDamage(_damage);
					SetPosCurs(5, 30);
					SetColor(13, 0);
					cout << '-' << _damage;
					SetColor(15, 0);
					break;
				case 2:
					_damage = _damage * 0.75;
					pl->TakeDamage(_damage);
					SetPosCurs(5, 30);
					SetColor(13, 0);
					cout << '-' << _damage;
					SetColor(15, 0);
					break;
				case 3:
					_damage = _damage * 0.75;
					pl->TakeDamage(_damage);
					SetPosCurs(5, 30);
					SetColor(13, 0);
					cout << '-' << _damage;
					SetColor(15, 0);
					break;
				case 0:
					pl->TakeDamage(_damage);
					SetPosCurs(5, 30);
					SetColor(13, 0);
					cout << '-' << _damage;
					SetColor(15, 0);
					break;
				}
			}
			SetPosCurs(5, 80);
			cout << "                         ";
			if (pl->GetHP() < 0)
			{
				pl = &Player();
				return 0;
			}
		}
		system("pause");
		system("cls");
		return 1; //1 - продолжить 0 - игра с начала
	}
};