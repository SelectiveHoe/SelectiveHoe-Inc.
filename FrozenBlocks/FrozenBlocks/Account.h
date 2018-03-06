#pragma once
#include "include.h"
#include "Inventory.h"

using namespace curse;

class Account
{
protected:
	string _userName;
	string _userPassword;

	int _level = 1;

	int _strength = 1;
	int _luck = 1;
	int _agility = 1;
	int _charisma = 1;

	double _maxhp = 10;
	double _hp = _maxhp;

	double _maxArmor = 0;
	double _armor = _maxArmor;

	int _money = 0;
	
	Item inv[3][6];
public:
	Account() {}
	Account(string suername, string userPassword)
	{
		_userName = suername;
		_userPassword = userPassword;
	}
	Account(string suername, string userPassword, int level, int strength, int luck, int agility, int charisma, double maxhp, double maxarmor, int money, double hp, double armor, Item invObj[3][6])
	{
		_userName = suername;
		_userPassword = userPassword;
		_level = level;
		_strength = strength;
		_luck = luck;
		_agility = agility;
		_charisma = charisma;
		_maxhp = maxhp;
		_maxArmor = maxarmor;
		_money = money;
		_hp = hp;
		_armor = armor;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				inv[i][j] = invObj[i][j];
			}
		}
	}

	void SaveAccountToDataBase()
	{		
		string acc = GetAccountInString();
		ifstream fout("AccountDataBase.txt", ios_base::in);
		string bufer;
		string textfromfile;
		bool accinfile = false;
		char buf[1000];
		fout.getline(buf, 1000);
		bufer = buf;
		if (bufer == "")
		{
			ofstream fin("AccountDataBase.txt", ios_base::app);
			fin << acc << endl;
			fin.close();
		}
		else
		{
			while (bufer != "")
			{
				char obj[1000];								
				int siz = _userName.size() + _userPassword.size() + 1;
				if (bufer.substr(0, siz) == acc.substr(0, siz))
				{
					textfromfile += acc;
					textfromfile += '\n';
					accinfile = true;
				}
				else
				{
					if (bufer != "")
					{
						textfromfile += bufer;
						textfromfile += '\n';
					}
					else
					{
						return;
					}
				}
				fout.getline(obj, 1000);
				bufer = obj;
			}
			ofstream fin("AccountDataBase.txt", ios_base::trunc);
			if (!accinfile)
			{
				textfromfile += acc;
			}
			fin << textfromfile;
			fin.close();
		}
		fout.close();
	}
	string GetuserName() { return _userName; }
	string GetuserPassword() { return _userPassword; }
	int GetLevel() { return _level; }
	
	int GetStrength() { return _strength; }
	int GetLuck() { return _luck; }
	int GetAgility() { return _agility; }
	int GetCharisma() { return _charisma; }

	string GetAccountInString()
	{
		//_userName << "|" << _userPassword << "|" << _level << "|" << _strength << "|" << _luck << "|" << _agility << "|" << _charisma << "|" << _maxhp << "|" << _maxArmor << "|" << _money << endl;
		string ret;
		char buf[255];
		ret += _userName;
		ret += "|";
		ret += _userPassword;
		ret += "|";
		_itoa_s(_level, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_strength, buf, 10);
		ret += buf;
		ret += "|"; 
		_itoa_s(_luck, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_agility, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_charisma, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_maxhp, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_maxArmor, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_money, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_hp, buf, 10);
		ret += buf;
		ret += "|";
		_itoa_s(_armor, buf, 10);
		ret += buf;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				ret += ":";
				string itemSID = inv[i][j].GetSID();
				ret += itemSID;
			}
		}
		ret += ";";
		return ret;
	}

	double GetMaxHP() { return _maxhp; }
	double GetHP() { return _hp; }
	double GetMaxArmor() { return _maxArmor; }
	double GetArmor() { return _armor; }

	int GetMoney() { return _money; }
	Item(&GetInv())[3][6]{ return inv; }

	void SetAccount(string suername, string userPassword, int level, int strength, int luck, int agility, int charisma, double maxhp, double maxarmor, int money, double hp, double armor,Item invObj[3][6])
	{
		_userName = suername;
		_userPassword = userPassword;
		_level = level;
		_strength = strength;
		_luck = luck;
		_agility = agility;
		_charisma = charisma;
		_maxhp = maxhp;
		_maxArmor = maxarmor;
		_money = money;
		_hp = hp;
		_armor = armor;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				inv[i][j] = invObj[i][j];
			}
		}
	}

	Account operator = (Account obj)
	{
		this->_userName = obj._userName;
		this->_userPassword = obj._userPassword;
		this->_strength = obj._strength;
		this->_money = obj._money;
		this->_maxhp = obj._maxhp;
		this->_maxArmor = obj._maxArmor;
		this->_luck = obj._luck;
		this->_level = obj._level;
		this->_charisma = obj._charisma;
		this->_agility = obj._agility;
		this->_hp = obj._hp;
		this->_armor = obj._armor;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				this->inv[i][j] = obj.inv[i][j];
			}
		}
		return *this;
	}
	bool operator == (Account obj)
	{
		return this->_userName == obj._userName && this->_userPassword == obj._userPassword && 	this->_strength == obj._strength && this->_money == obj._money && this->_maxhp == obj._maxhp && this->_maxArmor == obj._maxArmor && this->_luck == obj._luck && this->_level == obj._level && 	this->_charisma == obj._charisma && this->_agility == obj._agility && this->_hp == obj._hp && this->_armor == obj._armor;
	}
};
