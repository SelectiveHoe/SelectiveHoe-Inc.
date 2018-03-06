#pragma once
#include "include.h"

class Player
{
protected:
	string _icon = { (char)62,(char)62 };

	int _level = 1;

	int _PlayerPosX;
	int _PlayerPosY;

	int _strength = 1;
	int _luck = 1;
	int _agility = 1;
	int _charisma = 1;

	double _maxhp = 10;
	double _hp = _maxhp;

	double _maxArmor = 0;
	double _Armor = _maxArmor;
	double _damage = _strength * 10;
	int _money = 0;

public:
	Player() {}

	void SetPos(int X, int Y)
	{
		_PlayerPosX = X;
		_PlayerPosY = Y;
	}
	void SetIcon(string icon) { _icon = icon; }

	void LevelUp()
	{
		double chisforhp = _hp / _maxhp;
		_maxhp = _maxhp + (_maxhp * 0.25);
		_hp = _maxhp * chisforhp;

		_level++;
	}

	void GiveMaxHP() { _hp = _maxhp; }
	void TakeAwayHP(double damage) { _hp -= damage; }
	void GiveHP(double amount)
	{
		if (_hp + amount > _maxhp)
		{
			_hp = _maxhp;
		}
		else
		{
			_hp += amount;
		}
	}
	void SetMaxHP(int maxhp) { _maxhp = maxhp; }
	void SetLevel(int newlevel) { _level = newlevel; }

	void SetMaxArmor(double maxArmor) { _maxArmor = maxArmor; }
	void TakeAwayArmor(double damage) 
	{ 
		_Armor -= damage;
	}
	void GiveArmor(double armor) 
	{ 
		if (_Armor + armor > _maxArmor)
		{
			_Armor = _maxArmor;
		}
		else
		{
			_Armor += armor;
		}
	}

	void TakeDamage(double damage)
	{
		if (_Armor < 0)
		{
			_hp = _hp - damage;
		}
		else if ((_Armor - (damage/2)) < 0)
		{
			int awayhp = (damage / 2) - _Armor;
			_Armor = -1;
			_hp -= awayhp;
		}
		else
		{
			_Armor -= (damage / 2);
		}
	}

	void TakeMoney(int amount)
	{
		for (int i = 0; i < amount; i++)
		{
			_money++;
		}
		SetPosCurs(34, 11);
		cout << "     ";
		SetPosCurs(34, 11);
		cout << _money;
	}
	void TakeAwayMoney(int amount)
	{
		for (int i = 0; i < amount; i++)
		{
			_money--;
		}
		SetPosCurs(34, 11);
		cout << "     ";
		SetPosCurs(34, 11);
		cout << _money;
	}

	void SetNewSLAC(int s, int l, int a, int c)
	{
		_strength = s;
		_luck = l;
		_agility = a;
		_charisma = c;
	}
	int GetSLAC(string slac)
	{
		if (slac == "strength")
		{
			return _strength;
		}
		else if (slac == "luck")
		{
			return _luck;
		}
		else if (slac == "agility")
		{
			return _agility;
		}
		else if (slac == "charisma")
		{
			return _charisma;
		}
		return 999; // error
	}

	int GetPosX() { return _PlayerPosX; }
	int GetPosY() { return _PlayerPosY; }
	string GetIcon() { return _icon; }
	int GetLevel() { return _level; }
	int GetMoney() { return _money; }
	double GetHP() { return _hp; }
	double GetMaxHP() { return _maxhp; }
	double GetMaxArmor() { return _maxArmor; }
	double GetArmor() { return _Armor; }
	double GetDamage() 
	{
		_damage = _strength * 10;
		return  _damage;
	}

	void ShowPlayer()
	{
		SetPosCurs(_PlayerPosX + 1, (_PlayerPosY * 2) + 2);
		SetColor(0, 7);
		cout << _icon;
		SetColor(15, 0);
	}
};
