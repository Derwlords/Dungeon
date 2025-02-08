#include <iostream>

#include "Enemy.h"
#include "Player.h"
#include "time.h"


void Action(Player& Player, Enemy& enemy)
{
	while (true)
	{
		char Action = Player.Action();
		system("cls");
		switch (Action)
		{
		case 'a':
			Player.Fight(enemy);
			Player.Win(enemy);
			Player.Doodge(enemy, Player);
			break;
		case 'l':
			Player.BufforDebuff(enemy);
			Player.Win(enemy);
			Player.Doodge(enemy, Player);
			break;
		case 'h':
			Player.UseHealthPotion();
			Player.Doodge(enemy, Player);
			break;
		case 's':
			Player.CheckPlayerStatus();
			break;
		default:
			break;
		}

		if (Player.GetStatus() || enemy.GetStatus())
		{

			break;
		}
	}
}

void main()
{
	srand(time(NULL));

	Player Player;
	while (true)
	{
		Enemy enemy;
		enemy.MonsterGenerateon(Player);
		
		Action(Player, enemy);

		if (Player.GetStatus())
		{
			std::cout << "\nYou want Restart?\n";
			//TODO restart;
			break;
		}
	}

	system("pause");
}