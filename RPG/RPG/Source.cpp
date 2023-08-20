#include "Enemy.h"
#include "Player.h"
#include "time.h"


void main()
{
	srand(time(NULL));

	Player Player;
	while (true)
	{
		Enemy enemy;
		enemy.MonsterGenerateon(Player);
		while (true)
		{
			
			char Action = Player.Action() ;
			switch (Action)
			{
			case 'a':
				Player.Fight(enemy);
				if (enemy.GetStatus())
				{
					system("cls");
					Player.LvlUp();
					Player.PlayerGold(enemy.GetGold());
					break;
				}
				if (Player.Doodge() == false)
				{
					enemy.Fight(Player);
					if (Player.GetStatus())
					{
						system("cls");
						std::cout << "You Lose, in game you take: " << Player.GetGold() << " Gold";
						break;
					}
				}
				break;
			case 'l':
				Player.BufforDebuff(enemy);
				if (enemy.GetStatus())
				{
					system("cls");
					Player.LvlUp();
					Player.PlayerGold(enemy.GetGold());
					break;
				}
				if (Player.Doodge() == false)
				{
					enemy.Fight(Player);
					if (Player.GetStatus())
					{
						system("cls");
						std::cout << "You Lose, in game you take: " << Player.GetGold() << " Gold";
						break;
					}
				}
				break;
			case 'h':
				Player.UseHealthPotion();
				if (Player.Doodge() == false)
				{
					enemy.Fight(Player);
					if (Player.GetStatus())
					{
						system("cls");
						std::cout << "You Lose, in game you take: " << Player.GetGold() << " Gold";
						break;
					}
				}
				break;
			case 's':
				Player.CheckPlayerStatus();
				break;
			default:
				break;
			}
			
			if (Player.GetStatus()||enemy.GetStatus())
			{
				
				break;
			}
		}

		if (Player.GetStatus())
		{
			std::cout << "\nYou want Restart?\n";
			//TODO Do restart;
			break;
		}
	}
}