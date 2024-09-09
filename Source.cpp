#include <iostream>
#include <algorithm>
using namespace std;

class Map
{
public:
	int World[10][10];

	Map()
	{
		Init();
	}

	void Init()
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (i == 0 || i == 9 || j == 0 || j == 9)
				{
					World[i][j] = -1;
				}
				else
				{
					World[i][j] = 0;
				}
			}
		}
	}
};

class Player
{
private:
	int XPosition = 0;
	int YPosition = 0;

public:
	void Move(char Input)
	{
		switch (Input)
		{
		case 'w':
			YPosition--;
			YPosition = max(1, YPosition);
			YPosition = min(YPosition, 8);
			break;
		case 'a':
			XPosition--;
			XPosition = max(1, XPosition);
			XPosition = min(XPosition, 8);
			break;
		case 's':
			YPosition++;
			YPosition = max(1, YPosition);
			YPosition = min(YPosition, 8);
			break;
		case 'd':
			XPosition++;
			XPosition = max(1, XPosition);
			XPosition = min(XPosition, 8);
			break;
		default:
			break;
		}
	}

	void SetPosition(int X, int Y)
	{
		XPosition = X;
		YPosition = Y;
	}
	int GetXPosition()
	{
		return XPosition;
	}
	int GetYPosition()
	{
		return YPosition;
	}

};

class GameManager
{
public:
	GameManager()
	{
		map = new Map;
	}

	Map* map;
	Player* player
		;

	void PlayerLogIn()
	{
		player = new Player;

		map->World[1][1] = 1;
		player->SetPosition(1, 1);
	}

	void PlayerMove(char Input)
	{
		map->World[player->GetYPosition()][player->GetXPosition()] = 0;
		player->Move(Input);
		map->World[player->GetYPosition()][player->GetXPosition()] = 1;
	}

	void Render()
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (map->World[i][j] == 0)
					cout << ' ';
				if (map->World[i][j] == 1)
					cout << '*';
				if (map->World[i][j] == -1)
					cout << '#';
			}
			cout << endl;
		}
	}
};

int main()
{

	GameManager* Game = new GameManager;
	Game->PlayerLogIn();

	Game->Render();
	while (true)
	{
		cout << "Enter the Player's Movement : w, a, s, d" << endl;
		char Input;
		cin >> Input;
		Game->PlayerMove(Input);
		Game->Render();
	}


	return 0;
}