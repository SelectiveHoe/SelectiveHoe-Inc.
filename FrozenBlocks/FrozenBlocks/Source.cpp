#include "GameScripts.h"
#include "Menu.h"
#include "AccountDataBase.h"

using namespace curse;

void UserMenu(Account user, AccountDataBase DB)
{
	for (int i = 0; i < 4; i++)
	{
		SetPosCurs(7 + i, 21);
		cout << "                                         ";
	}
	Menu UserMenu;
	UserMenu.AddButton("Play");
	UserMenu.AddButton("Leaderboard");
	UserMenu.AddButton("Exit");
	SetPosCurs(10, 0);

	bool globalexit = false;
	int menuid;
	while (!globalexit)
	{
		menuid = 4;
		menuid = UserMenu.ActivateMenu(7, 21);
		if (menuid == 1)
		{
			system("cls");
			GameScripts game(user, DB);
			bool exit = false;
			while (!exit)
			{
				game.GenerateMap();
				game.ShowMap();
				game.ShowPlayerStats();
				if (game.SpawnPlayer() == 0)
				{
					system("cls");
					PrintLogo(1, 21);
					exit = true;
					Sleep(500);
				}
			}
		}
		else if (menuid == 2)
		{
			system("cls");
			PrintLogo(1, 21);
			SetPosCurs(7, 24);
			cout << "Name: ";
			SetPosCurs(7, 21);
			cout << "#";
			SetPosCurs(7, 60);
			cout << "Score:";
			DB.SordDataBase();
			for (int i = 0; i < 29; i++)
			{
				if (i < DB.GetSizeDataBase())
				{
					SetPosCurs(9 + i, 24);
					cout << DB.GetAcc(i).GetuserName();
					SetPosCurs(9 + i, 21);
					cout << i;
					SetPosCurs(9 + i, 60);
					cout << DB.GetAcc(i).GetLevel();
				}
			}
			bool exittwo = false;
			while (!exittwo)
			{
				if ((GetKeyState(VK_ESCAPE) & 0x8000) != 0)
				{
					system("cls");
					PrintLogo(1, 21);
					exittwo = true;
					DB.LoadDataBase();
				}
			}
		}
		else if (menuid == 0)
		{
			system("cls");
			PrintLogo(1, 21);
			globalexit = true;
		}
	}
}

void main()
{
	cout.setf(ios::fixed);
	cout.precision(2);

	int menuid = 1;
	while (menuid != 0)
	{
		system("mode con cols=124 lines=40");
		ShowConsoleCursor(FALSE);
		SetTitle();
		AccountDataBase DB;
		Account User;
		DB.LoadDataBase();
		DB.SaveDataBase();
		PrintLogo(1, 21);
		Menu MainMenu;
		MainMenu.AddButton("Log in");
		MainMenu.AddButton("Registration");
		MainMenu.AddButton("Exit");
		menuid = MainMenu.ActivateMenu(7, 21);
		if (menuid == 1)
		{
			bool exit = false;
			while (!exit)
			{
				SetPosCurs(7, 21);
				cout << "     ";
				SetPosCurs(8, 21);
				cout << "            ";
				SetPosCurs(9, 21);
				cout << "    ";

				SetPosCurs(7, 21);
				cout << "Log in";
				SetPosCurs(8, 0);
				for (int i = 0; i < 123; i++)
				{
					cout << " ";
				}
				SetPosCurs(9, 21);
				cout << "Password";
				SetPosCurs(10, 0);
				for (int i = 0; i < 123; i++)
				{
					cout << " ";
				}
				ShowConsoleCursor(TRUE);
				SetPosCurs(8, 21);
				char buf[255];
				cin.getline(buf, 255);
				string login = buf;

				SetPosCurs(10, 21);
				cin.getline(buf, 255);
				string password = buf;

				User = DB.CheckAccount(login, password);
				if (User.GetuserName() == "ERROR" && User.GetuserPassword() == "ERROR")
				{
					SetPosCurs(38, 2);
					cout << "Invalid login and password...";
				}
				else if (User.GetuserName() == "ERROR" && User.GetuserPassword() == "PASSWORD")
				{
					SetPosCurs(38, 2);
					cout << "                                     ";
					SetPosCurs(38, 2);
					cout << "Invalid password...";
				}
				else
				{
					exit = true;
					ShowConsoleCursor(FALSE);
					
				}
			}
			UserMenu (User, DB);
		}
		else if (menuid == 2)
		{
			bool exit = false;
			ShowConsoleCursor(TRUE);
			while (!exit)
			{
				SetPosCurs(7, 21);
				cout << "     ";
				SetPosCurs(8, 21);
				cout << "            ";
				SetPosCurs(9, 21);
				cout << "    ";

				SetPosCurs(7, 21);
				cout << "Log in";
				SetPosCurs(8, 0);
				for (int i = 0; i < 123; i++)
				{
					cout << " ";
				}
				SetPosCurs(9, 21);
				cout << "Password";
				SetPosCurs(10, 0);
				for (int i = 0; i < 123; i++)
				{
					cout << " ";
				}
				SetPosCurs(11, 21);
				cout << "Confirm password";
				SetPosCurs(12, 0);
				for (int i = 0; i < 123; i++)
				{
					cout << " ";
				}
				ShowConsoleCursor(TRUE);
				SetPosCurs(8, 21);
				char buf[255];
				cin.getline(buf, 255);
				string login = buf;

				SetPosCurs(10, 21);
				cin.getline(buf, 255);
				string password = buf;

				SetPosCurs(12, 21);
				cin.getline(buf, 255);
				string confpassword = buf;

				exit = true;
				if (password != confpassword)
				{
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Invalid passwords...";
					exit = false;
				}
				for (int i = 0; i < login.size(); i++)
				{
					if (login[i] == '|')
					{
						SetPosCurs(38, 0);
						for (int i = 0; i < 123; i++)
						{
							cout << " ";
						}
						SetPosCurs(38, 2);
						cout << "Login contains incorrect characters...";
						exit = false;
					}
				}

				for (int i = 0; i < password.size(); i++)
				{
					if (password[i] == '|')
					{
						SetPosCurs(38, 0);
						for (int i = 0; i < 123; i++)
						{
							cout << " ";
						}
						SetPosCurs(38, 2);
						cout << "Password contains incorrect characters...";
						exit = false;
					}
				}

				if (password.size() > 25)
				{
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Password too long...";
					exit = false;
				}

				if (login.size() > 25)
				{
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Login too long...";
					exit = false;
				}

				if (DB.CheckAccount(login, password).GetuserName() != "ERROR" && DB.CheckAccount(login, password).GetuserPassword() != "PASSWORD" || DB.CheckAccount(login, password).GetuserPassword() != "ERROR")
				{
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Account with such login already exists...";
					exit = false;
				}



				if (login.size() < 3)
				{
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Too short login...";
					exit = false;
				}

				if (password.size() < 3)
				{
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Too short password...";
					exit = false;
				}

				if (exit)
				{
					Account obj(login, password);
					DB.AddToDataBase(obj);
					obj.SaveAccountToDataBase();
					SetPosCurs(38, 0);
					for (int i = 0; i < 123; i++)
					{
						cout << " ";
					}
					SetPosCurs(38, 2);
					cout << "Account successfully created!";
				}
			}
			ShowConsoleCursor(FALSE);
		}
	}
}

