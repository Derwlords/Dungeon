
#include "Enemy.h"

Enemy::Enemy()
{
}
Monsters monster[EnemyType::MaxType]{
	{1,'s',"Slime",1,1,10},
	{2,'l',"Skelet",3,2,20},
	{3,'k',"SkeletKnight",5,1,40},



	{4,'z',"Zombi",10,4,50},
	{5,'o',"Orc",20,6,60},
	{6,'v',"Vampire",40,8,90},


	{7,'m',"Minotavr",60,20,100},
	{8,'d',"Dragon",90,30,110},
	{9,'h',"Hydra",110,50,120},


	{10,'M',"MiniBoss",800,100,500},
	{11,'F',"FinalBoss",2000,400,100000}
};

void Enemy::MonsterGenerateon(Player& Player)
{
	if (Player.GetPlayerLVL() <= 10)
	{
		id = rand() % 3;
		
	}
	else if (Player.GetPlayerLVL() <= 20)
	{
		id = rand() % 6;
	}
	else if (Player.GetPlayerLVL() <= 30)
	{
		id = rand() % 9;
	}
	else if (Player.GetPlayerLVL() <= 50)
	{
		id = rand() % 12;
	}

	symbol = monster[id].symbol;
	Name = monster[id].Name;
	HpScale = monster[id].HPScale;
	DamageScale = monster[id].DamageScale;
	GoldScale = monster[id].GoldScale;

	if(Player.GetPlayerLVL())
	HP =  HpScale * Player.GetPlayerLVL();
	Damage =   DamageScale * Player.GetPlayerLVL();
	Gold =  GoldScale * Player.GetPlayerLVL();
	

	UI();
	std::cout << symbol << " " << Name << "\n";
	std::cout << "Has " << Damage << " damage and " <<  HP  << " Health\n";
	UI();
		
}

void Enemy::Fight(BaseCharacter& Attacked)
{
	Attack(Attacked);
}

void Enemy::BufforDebuff( BaseCharacter& Attacked)
{
}

void Enemy::StopBufforDebuff(Spells& Spell, BaseCharacter& Attacked)
{
}

void Enemy::AttackedSpell(Spells& Spell, BaseCharacter& Attacked)
{
}
