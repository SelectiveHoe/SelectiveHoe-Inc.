#pragma once
#include "include.h"
#include "Menu.h"
using namespace curse;

class Item
{
protected:
	string _name = "<NoneNameItem>";
	int _id = 0;
	int _rarity = 0;
	bool isUse = false;

	int bufStrength = 0;
	int bufLuck = 0;
	int bufAgility = 0;
	int bufCharisma = 0;

	double Heal = 0;
	double bufArmor = 0;

	string _icon;
public:
	Item()
	{
		switch (_id)
		{
		case 0:
			_icon = icon_empty;
			break;
		case 1:
			_icon = icon_sword;
			break;
		case 2:
			_icon = icon_helmet;
			break;
		case 3:
			_icon = icon_ñhestpiece;
			break;
		case 4:
			_icon = icon_leggings;
			break;
		case 5:
			_icon = icon_potion;
			break;
		case 6:
			_icon = icon_item;
			break;
		}
	}
	Item(int id, int rarity)
	{
		_rarity = rarity;
		SetId(id);
	}
	Item(string name, int id, int rarity, int s, int l, int a, int c, int bufA, double heal)
	{
		_name = name;
		_rarity = rarity;
		SetId(id);

		bufStrength = s;
		bufLuck = l;
		bufAgility = a;
		bufCharisma = c;

		bufArmor = bufA;

		Heal = heal;
	} //êîíñòðóêòîð äëÿ ìå÷à
	Item(int id, int rarity, int _isUse, int s, int l, int a, int c,double heal, double bufArm)
	{
		_rarity = rarity;
		SetId(id);

		if (_isUse == 0)
		{
			isUse = false;
		}
		else
		{
			isUse = true;
		}

		bufStrength = s;
		bufLuck = l;
		bufAgility = a;
		bufCharisma = c;

		Heal = heal;
		bufArmor = bufArm;

		string name;
		switch (rarity)
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
		switch (id)
		{
		case 1:
			name += "Swoard";
			break;
		case 2:
			name += "Helmet";
			break;
		case 3:
			name += "Chestpiece";
			break;
		case 4:
			name += "Leggings";
			break;
		case 5:
			name += "Potion";
			break;
		}
		if (name.size() > 1)
		{
			_name = name;
		}	
	}

	int GetId()
	{
		switch (_id)
		{
		case 0:
			_icon = icon_empty;
			break;
		case 1:
			_icon = icon_sword;
			break;
		case 2:
			_icon = icon_helmet;
			break;
		case 3:
			_icon = icon_ñhestpiece;
			break;
		case 4:
			_icon = icon_leggings;
			break;
		case 5:
			_icon = icon_potion;
			break;
		case 6:
			_icon = icon_item;
			break;
		}
		return _id;
	}
	string GetName() { return _name; }
	int GetRarity() { return _rarity; }
	bool GetIsUse() { return isUse; }

	double GetHeal() { return Heal; }
	int GetBufStrength() { return bufStrength; }
	int GetBufLuck() { return bufLuck; }
	int GetBufAgility() { return bufAgility; }
	int GetBufCharisma() { return bufCharisma; }
	double GetBufArmor() { return bufArmor; }
	int GetAmountBuf()
	{
		int amon = 0;
		if (bufStrength > 0)
		{
			amon++;
		}
		if (bufLuck > 0)
		{
			amon++;
		}
		if (bufAgility > 0)
		{
			amon++;
		}
		if (bufCharisma > 0)
		{
			amon++;
		}
		if (bufArmor > 0)
		{
			amon++;
		}
		if (Heal > 0)
		{
			amon++;
		}
		return amon;
	}

	void SetRarity(int rarity) { _rarity = rarity; }
	void SetId(int id) { _id = id; }
	void SetName(string name) { _name = name; }
	void toggleIsUse()
	{
		if (isUse)
		{
			isUse = false;
		}
		else
		{
			isUse = true;
		}
	}

	int GetCostItem() 
	{ 
		switch (_id)
		{
		case 1:
			switch (_rarity)
			{
			case 0:
				return 30;
				break;
			case 1:
				return 50;
				break;
			case 2:
				return 70;
				break;
			case 3:
				return 120;
				break;
			case 4:
				return 150;
				break;
			}
			break;
		case 2:
			switch (_rarity)
			{
			case 0:
				return 20;
				break;
			case 1:
				return 30;
				break;
			case 2:
				return 50;
				break;
			case 3:
				return 70;
				break;
			case 4:
				return 100;
				break;
			}
			break;
		case 3:
			switch (_rarity)
			{
			case 0:
				return 20;
				break;
			case 1:
				return 30;
				break;
			case 2:
				return 50;
				break;
			case 3:
				return 70;
				break;
			case 4:
				return 100;
				break;
			}
			break;
		case 4:
			switch (_rarity)
			{
			case 0:
				return 20;
				break;
			case 1:
				return 30;
				break;
			case 2:
				return 50;
				break;
			case 3:
				return 70;
				break;
			case 4:
				return 100;
				break;
			}
			break;
		case 5:
			switch (_rarity)
			{
			case 0:
				return 25;
				break;
			case 1:
				return 45;
				break;
			case 2:
				return 60;
				break;
			case 3:
				return 80;
				break;
			case 4:
				return 100;
				break;
			}
			break;
		}
		return 0;
	}

	void PrintIconEmpty(int x, int y)
	{
		int count = 0;
		SetPosCurs(x, y);
		for (int i = 0; i < _icon.size(); i++)
		{
			cout << icon_empty[i];
			count++;
			if (count == 14)
			{
				x++;
				SetPosCurs(x, y);
				count = 0;
			}
		}
	}
	void PrintIcon(int x, int y)
	{
		int count = 0;
		SetPosCurs(x, y);
		for (int i = 0; i < _icon.size(); i++)
		{
			cout << _icon[i];
			count++;
			if (count == 14)
			{
				x++;
				SetPosCurs(x, y);
				count = 0;
			}
		}
	}
	void PrintName()
	{
		if (_id == 0)
		{
			cout << "[Empty]";
		}
		else
		{
			switch (_rarity)
			{
			case 0:
				cout << _name;
				break;
			case 1:
				SetColor(2, 0);
				cout << _name;
				break;
			case 2:
				SetColor(1, 0);
				cout << _name;
				break;
			case 3:
				SetColor(5, 0);
				cout << _name;
				break;
			case 4:
				SetColor(14, 0);
				cout << _name;
				break;
			}
			SetColor(15, 0);
		}
	}

	string GetSID()
	{
		string SID;

		SID += to_string(_id);
		SID += '|';
		SID += to_string(_rarity);
		SID += '|';
		if (isUse)
			SID += '1';
		else
			SID += '0';
		SID += '|';
		SID += to_string(bufStrength);
		SID += '|';
		SID += to_string(bufLuck);
		SID += '|';
		SID += to_string(bufAgility);
		SID += '|';
		SID += to_string(bufCharisma);
		SID += '|';
		SID += to_string(Heal);
		SID += '|';
		SID += to_string(bufArmor);

		return SID;
	}

	Item operator = (Item v1)
	{
		this->SetName(v1.GetName());
		this->SetId(v1.GetId());
		this->SetRarity(v1.GetRarity());
		isUse = v1.GetIsUse();

		bufStrength = v1.GetBufStrength();
		bufLuck = v1.GetBufLuck();
		bufAgility = v1.GetBufAgility();
		bufCharisma = v1.GetBufCharisma();
		bufArmor = v1.GetBufArmor();

		Heal = v1.Heal;
		return v1;
	}

	friend bool operator ==(Item &obj, Item &obj2)
	{
		return obj.GetSID() == obj2.GetSID();
	}

	friend bool operator !=(Item &obj, Item &obj2)
	{
		return obj.GetSID() != obj2.GetSID();
	}
};
