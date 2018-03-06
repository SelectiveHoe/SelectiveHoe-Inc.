#pragma once
#include "Block.h"
using namespace curse;

class World
{
protected:
	int _sizeMapX = 30;
	int _sizeMapY = 60;
	Block _map[30][60];
	int spawn;
	int exit = 0;
	
	void CreateRoom(int amount)
	{
		for (int a = 0; a < amount; a++)
		{
			int sizeroom = 5 + rand() % 15;
			int x = 1 + rand() % (29);
			int y = 1 + rand() % (59);

			while (_map[x][y].GetId() != 0 || x + sizeroom > 29 || y + sizeroom > 59)
			{
				x = 1 + rand() % (29);
				y = 1 + rand() % (59);
			}

			for (int i = 0; i < sizeroom; i++)
			{
				for (int j = 0; j < sizeroom; j++)
				{
					_map[x + i][y + j].SetId(0);
				}
			}
		}
	}
	void CreateExit() 
	{ 
		while (_map[exit][59].GetId() != 3)
		{
			exit = 1 + rand() % 29;
			if (_map[exit][58].GetId() == 0)
			{
				_map[exit][59].SetId(3);
				return;
			}
		}
	}
	void CreateSpawn()
	{
		_map[spawn][0].SetId(2);
	}
	void CreateWallsAround()
	{
		for (int i = 0; i < _sizeMapX; i++)
		{
			for (int j = 0; j < _sizeMapY; j++)
			{
				if (i == 0 || j == 0 || i == _sizeMapX - 1 || j == _sizeMapY - 1)
				{
					_map[i][j].SetId(1);
				}
			}
		}
	}
	void SpawnCoin(int amount)
	{
		for (int a = 0; a < amount; a++)
		{
			int x = 0;
			int y = 0;
			while (_map[x][y].GetId() != 0)
			{
				x = 1 + rand() % 29;
				y = 1 + rand() % 59;
			}
			_map[x][y].SetId(4);
		}
	}
public:
	World()
	{
		srand(time(0));
		spawn = 2 + rand() % 25;
		for (int i = 0; i < _sizeMapX; i++)
		{
			for (int j = 0; j < _sizeMapY; j++)
			{
				_map[i][j].SetId(1);
			}
		}

		for (int i = 0; i < 59; i++)
		{
			_map[spawn +1][i].SetId(0);
			_map[spawn][i].SetId(0);
			_map[spawn -1][i].SetId(0);
		}

		for (int i = 0; i < 5; i++)
		{
			int y = 1 + rand() % 59;
			for (int j = 1; j < 29; j++)
			{
				_map[j][y+1].SetId(0);
				_map[j][y].SetId(0);
				_map[j][y-1].SetId(0);
			}
		}

		CreateWallsAround();
		CreateRoom(5);
		CreateWallsAround();

		
		SpawnCoin(5);


		CreateExit();
		CreateSpawn();		
	}

	string GetBlockIcon(int x, int y) { return _map[x][y].GetIcon(); }
	void ShowWorld(int X, int Y)
	{
		for (int i = 0; i < _sizeMapX; i++)
		{
			SetPosCurs(X + i, Y);
			for (int j = 0; j < _sizeMapY; j++)
			{
				_map[i][j].ShowBlock();
			}
			cout << endl;
		}
	}
	bool GetBlockColision(int X, int Y) { return _map[X][Y].GetColision(); }
	int GetSpawn() { return spawn; }
	void ShowBlockXY(int x, int y) { _map[x][y].ShowBlock(); }
	int GetBlockID(int x, int y) { return _map[x][y].GetId(); }
	void SetBlockID(int x, int y, int id) { _map[x][y].SetId(id); }
	int GetExit() { return exit; }

	void GenerateHub()
	{
		for (int i = 0; i < _sizeMapX; i++)
		{
			for (int j = 0; j < _sizeMapY; j++)
			{
				_map[i][j].SetId(0);
			}
		}
		CreateWallsAround();

		_map[5][30].SetId(5);

		CreateExit();
		CreateSpawn();
	}

	void AddDropToBlock(Item obj, int x, int y)
	{
		_map[x][y].AddItem(obj);
	}
	int GetCountDrop(int x, int y)
	{
		return _map[x][y].GetSizeDrop();
	}
	void DeleteDropFromBlock(int id, int x, int y)
	{
		_map[x][y].DeleteDrop(id);
	}
	Item GetItemFromBlock(int id, int x, int y)
	{
		return _map[x][y].GetItem(id);
	}

	void OpenNewLevel()
	{
		_map[exit][59].SetColisionTrue();
	}
	void CloseNewLevel()
	{
		_map[exit][59].SetColisionFalse();
	}
};