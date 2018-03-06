#pragma once
#include "include.h"
#include "Account.h"
#include <algorithm>
using namespace std;

bool sortForLevel(Account obj, Account bojj) { return obj.GetLevel() > bojj.GetLevel(); }

class AccountDataBase
{
protected:
	Vector<Account> DataBase;

	
public:

	void SaveDataBase()
	{
		if (DataBase.GetCount() != 0)
		{
			//ofstream fin("AccountDataBase.txt", ios_base::trunc);
			//fin.close();
			for (int i = 0; i < DataBase.GetCount(); i++)
			{
				DataBase[i].SaveAccountToDataBase();
			}
		}
	}
	void LoadDataBase()
	{
		Vector<Account> cpy;
		ifstream fout("AccountDataBase.txt");
		string bufer;
		while (!fout.eof())
		{
			char obj[1000];
			fout.getline(obj, 1000);
			bufer = obj;
			// Начало парсера аккаунта из файла
			if (bufer.size() > 0)
			{
				int first = 0;
				int last = 0;
				while (bufer[last] != '|')
				{
					last++;
				}
				string login = bufer.substr(first, last);
				first = last + 1;
				last = 0;

				while (bufer[last + first] != '|')
				{
					last++;
				}
				string password = bufer.substr(first, last);
				//cout << login << " " << password << endl;
				first = last + first + 1;
				last = 0;

				int levl;

				int s;
				int l;
				int a;
				int c;

				double maxhp;
				double hp;
				double maxarmor;
				double armor;

				int money;
				for (int i = 0; i < 10; i++)
				{
					string bufe;
					bool exit = false;
					while (!exit)
					{
						exit = false;
						if (bufer[first] == '|')
						{
							exit = true;
						}
						else if (bufer[first] == ':')
						{
							exit = true;
						}
						else 
						{
							bufe += bufer[first];
						}
						first++;
					}
					if (i == 0)
					{
						levl = atoi(bufe.c_str());
					}
					if (i == 1)
					{
						s = atoi(bufe.c_str());
					}
					if (i == 2)
					{
						l = atoi(bufe.c_str());
					}
					if (i == 3)
					{
						a = atoi(bufe.c_str());
					}
					if (i == 4)
					{
						c = atoi(bufe.c_str());
					}
					if (i == 5)
					{
						maxhp = atoi(bufe.c_str());
					}
					if (i == 6)
					{
						maxarmor = atoi(bufe.c_str());
					}
					if (i == 7)
					{
						money = atoi(bufe.c_str());
					}
					if (i == 8)
					{
						hp = atoi(bufe.c_str());
					}
					if (i == 9)
					{
						armor = atoi(bufe.c_str());
					}
				}

				int id = 0;
				int rarity = 0;
				int isUse = 0;
				int bufS = 0;
				int bufL = 0;
				int bufA = 0;
				int bufC = 0;
				double heal = 0;
				double bufArmor = 0;

				Item inv[3][6];
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 6 ;j++)
					{					
						for (int o = 0; o < 9; o++)
						{
							string bufe;
							bool exit = false;
							while (!exit)
							{
								exit = false;
								if (bufer[first] == '|')
								{
									exit = true;
								}
								else if (bufer[first] == ':')
								{
									exit = true;
								}
								else if (bufer[first] == ';')
								{
									exit = true;
								}
								else
								{
									bufe += bufer[first];
								}
								first++;
							}
							switch (o)
							{
							case 0:
								id = atoi(bufe.c_str());
								break;
							case 1:
								rarity = atoi(bufe.c_str());
								break;
							case 2:
								isUse = atoi(bufe.c_str());
								break;
							case 3:
								bufS = atoi(bufe.c_str());
								break;
							case 4:
								bufL = atoi(bufe.c_str());
								break;
							case 5:
								bufA = atoi(bufe.c_str());
								break;
							case 6:
								bufC = atoi(bufe.c_str());
								break;
							case 7:
								heal = stod(bufe.c_str());
								break;
							case 8:
								bufArmor = stod(bufe.c_str());
								break;
							}
						}
						Item itm(id, rarity, isUse, bufS, bufL, bufA, bufC, heal, bufArmor);

						inv[i][j] = itm;
 					}
				}
				

				Account acc(login, password, levl, s, l, a, c, maxhp, maxarmor, money, hp, armor, inv);
				cpy.Add(acc);
			}
			else
			{
				DataBase = cpy;
				fout.close();
				return;
			}
		}
		DataBase = cpy;
		fout.close();
	}
	void AddToDataBase(Account obj)
	{
		DataBase.Add(obj);
	}

	int GetSizeDataBase() { return DataBase.GetCount(); }
	Account GetAcc(int id) { return DataBase[id]; }

	void SordDataBase()
	{
		vector<Account> obj;
		for (int i = 0; i < DataBase.GetCount(); i++)
		{
			obj.push_back(DataBase[i]);
		}
		sort(obj.begin(), obj.end(), sortForLevel);
		Vector<Account> cpy;
		for (int i = 0; i < obj.size(); i++)
		{
			cpy.Add(obj[i]);
		}
		DataBase = cpy;
	}

	Account CheckAccount(string login, string password)
	{
		for (int i = 0; i < DataBase.GetCount(); i++)
		{
			if (DataBase[i].GetuserName() == login)
			{
				if (DataBase[i].GetuserPassword() == password)
				{
					return DataBase[i];
				}
				else
				{
					Account obj("ERROR", "PASSWORD");
					return  obj;
				}
			}
		}
		Account obj("ERROR", "ERROR");
		return  obj;
	}
	AccountDataBase& operator=(const AccountDataBase& right)
	{
		if (right.DataBase.GetCount() != 0)
		{
			DataBase.Clear();
			for (int i = 0; i < DataBase.GetCount(); i++)
			{
				DataBase[i] = right.DataBase[i];
			}
		}
		return *this;
	}
};
