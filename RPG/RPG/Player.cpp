#include "Player.h"
#include "Spells.h"

Player::Player()
{
	std::cout << "Write you Name: ";

	std::cin >> Name;
	symbol = Name[0];
	
	ChooseClass();
	LVL = 1;
	Gold = 0;
	

	MonsterToLVLUp = 1;
	PlayerKilledgMonster = 0;
	AllKilledMonsters = 0;
	
	
	TemporaryDoodge = 0;
	TemporaryDamage = 0;
	TemporaryHP = 0;
	
}

void Player::LvlUp()
{
	if(MonsterToLVLUp == PlayerKilledgMonster)
	{
		LVL += 1;

		MonsterToLVLUp += 1;
		PlayerKilledgMonster = 0;
		if (LVL % 5 == 0)
		{
			DamageScale += DamageScale;
			HealPotion += HealPotion;
			HpScale += HpScale / 2 + HpScale;
		}
		if (LVL % 9 == 0)
		{
			DoodgeScale *= 2;
		}
		if (LVL % 3 == 0)
		{
			DoodgeChance += DoodgeScale;
		}
		MaxHp += HpScale * 2;
		if (HP < (MaxHp / 2))
		{
			HP = MaxHp / 2;
		}
		MaxMana += 10;
		Mana = MaxMana;
		ManaRegen += 1;

		HP += HpScale;
		Damage += DamageScale;

		std::cout << "You got the level,now your LVL: " << LVL << "\n";
		std::cout << "You damage is up,now your damage:" << Damage << "\n";
		std::cout << "You Max HP is up on " << HpScale << " its this time you have: " << HP << " HP\n";
		
	}
	

}

char Player::Action()
{

	char action;
	do {
		std::cout << "\nAttack(a)\nUse health potion(h)\nUse spell(l)\nCheck stats (s)\n";
		std::cin >> action;
	} while (action != 'a' && action != 's' && action != 'h' && action != 'l');
	return action;
}

void Player::UseHealthPotion()
{
	std::cout << "You use heal potion.\n";
	Heal(HealPotion);
}

void Player::Heal(int heal)
{
	UI();
	std::cout << "Player heal " << heal << std::endl;
	HP += heal;
	if (HP > MaxHp)
	{
	HP = MaxHp;
	}
	std::cout << "Health now: " << HP << std::endl;
	UI();
}

void Player::Doodge(BaseCharacter& Enemy, BaseCharacter& Player)
{
	if (Enemy.GetStatus() == false) 
	{
		int DoodgeTry = rand() % 200;
		if (DoodgeTry > DoodgeChance)
		{
			Enemy.Fight(Player);
			Lose();
		}
		else
		{
			std::cout << "\nYou doodge attack\n";
			UI();
		}
	}
}

void Player::ChooseClass()
{
	
	
	
	int PlayerClass;
	do 
	{
		std::cout << "Choose class:\nRogue (1)\nWar (2)\nKnight (3)\nPaladin (4)\n";
		std::cin >> PlayerClass;

	} while (PlayerClass < 1 && PlayerClass > 4);

	switch (PlayerClass)
	{
	case 1:
		Class = "Rogue";

		HpScale = 3;
		HP = 3;
		MaxHp = HP;
		HealPotion = 10;

		Damage = 2;
		DamageScale = 3;
		
		DoodgeChance = 10;
		DoodgeScale = 3;
		
		Mana = 100;
		MaxMana = Mana;
		ManaRegen = 5;

		ClassSpells[0] = { "x2 damage",true,2,10,3,2,eDamageUp };
		ClassSpells[1] = { "Up doodge",true,5,15,5,2,eDoodgeUp};
		ClassSpells[2] = { "scratch",false,50 * Damage,30,3,0,eAttackedSpell };
		

		
		break;
	case 2:
		Class = "War";

		HpScale = 4;
		HP = 4;
		MaxHp = HP + HpScale * 2;
		HealPotion = 8;
		Damage = 3;
		DamageScale = 3;

		DoodgeChance = 4;
		DoodgeScale = 2;
		break;
	case 3:
		Class = "Knight";

		HpScale = 5;
		HP = 3;
		MaxHp = HP;
		HealPotion = 7;
		Damage = 1;
		DamageScale = 3;

		DoodgeChance = 5;
		DoodgeScale = 1;
		break;
	case 4:
		Class = "Paladin";

		HpScale = 6;
		HP = 15;
		MaxHp = HP * 2;
		HealPotionScale = 15;

		Damage = 1;
		DamageScale = 1;
		
		DoodgeChance = 1;
		DoodgeScale = 1;
	
		
		break;
	}
}

int Player::PlayerGold(int TakedGold)
{
	std::cout << "You Win and take: " << TakedGold << " Gold\n";
	Gold += TakedGold;
	return Gold;
}

void Player::CheckPlayerStatus()
{
	std::cout << "\nAttack: " << Damage << "\nMaxHP: " << MaxHp << "\nHP: " << HP << std::endl;
	std::cout << "Heal Potion Heling: " << HealPotion << "\nDoodgeChance: " << DoodgeChance << std::endl;
	std::cout << "Monster Killed now: " << PlayerKilledgMonster << std::endl;
	std::cout << "Monster need to LvlUp: " << MonsterToLVLUp << std::endl;
	std::cout << "All killed monster: " << AllKilledMonsters << std::endl;
	std::cout << "How many gold do you have: " << Gold << std::endl;
	
}

void Player::BufforDebuff( BaseCharacter& Attacked)
{
	for (int i = 0; i < 5; i++)
	{
		if (ClassSpells[i].CooldownTimer > 0)
		{
			std::cout << "Spell on cooldown " << ClassSpells[i].CooldownTimer << " more rounds" << std::endl;
		}
		else
		{
			std::cout << ClassSpells[i].SpellName << " " << i + 1 << std::endl;
		}
		

	}
	int SpellNumber;
	bool SpellCD;
	do 
	{
		SpellCD = true;
		std::cout << "\nPress 1 to 5: ";
		
		std::cin >> SpellNumber;
		SpellNumber--;
		if (ClassSpells[SpellNumber].CooldownTimer == 0 )
		{
			SpellCD = false;
		}
	} while (SpellNumber < 0 || SpellNumber > 4 || SpellCD );
	
	
	if (ClassSpells[SpellNumber].Self)
	{
		switch (ClassSpells[SpellNumber].SpellType)
		{
		case eDamageUp:
			TemporaryDamage = Damage;
			Damage *= ClassSpells[SpellNumber].BufforDebaf;
			TemporaryDamage = Damage - TemporaryDamage;
			ClassSpells[SpellNumber].CooldownTimer = ClassSpells[SpellNumber].Cooldown;
			ClassSpells[SpellNumber].BufforDebuffStop = ClassSpells[SpellNumber].DurBufforDebuff;
			break;
		case eDoodgeUp:
			TemporaryDoodge = DoodgeChance;
			DoodgeChance *= ClassSpells[SpellNumber].BufforDebaf;
			TemporaryDoodge = DoodgeChance - TemporaryDoodge;
			ClassSpells[SpellNumber].CooldownTimer = ClassSpells[SpellNumber].Cooldown;
			ClassSpells[SpellNumber].BufforDebuffStop = ClassSpells[SpellNumber].DurBufforDebuff;
			break;
		case eHeal:
			TemporaryHP = HP;
			HP *= ClassSpells[SpellNumber].BufforDebaf;
			TemporaryHP = HP - TemporaryHP;
			ClassSpells[SpellNumber].CooldownTimer = ClassSpells[SpellNumber].Cooldown;
			ClassSpells[SpellNumber].BufforDebuffStop = ClassSpells[SpellNumber].DurBufforDebuff;
			break;

		}
	}
	else
	{
		AttackedSpell(ClassSpells[SpellNumber], Attacked);
	}
}

void Player::StopBufforDebuff(Spells& Spell, BaseCharacter& Attacked)
{
	for (int i = 0; i < 5; i++)
	{
		switch (ClassSpells[i].SpellType)
		{
		case eDamageUp:
			Damage -= TemporaryDamage ;
			break;
		case eDoodgeUp:
			DoodgeChance -= TemporaryDoodge;
			break;
		case eHeal:
			HP -= TemporaryHP;
			break;

		}
	}
	
}

void Player::AttackedSpell(Spells& Spell, BaseCharacter& Attacked)
{
	UI();
	std::cout << symbol << " attack " << Attacked.GetSymbol() << "\nAnd dealt: " << Spell.BufforDebaf << " damage\n";
	Attacked.SetHealth(Spell.BufforDebaf) ;
	if (Attacked.GetHealth() <= 0)
	{
		
		Attacked.Dead = true;
	}
	else
	{
		std::cout << Attacked.GetName() << " has " << Attacked.GetHealth() << " HP left\n\n\n";
	}
	Spell.CooldownTimer = Spell.Cooldown;
}

void Player::Lose()
{
	if (GetStatus())
	{
		system("cls");
		std::cout << "You Lose, in game you take: " << GetGold() << " Gold";
		
	}
}

void Player::Win(BaseCharacter& Enemy)
{
	if (Enemy.GetStatus())
	{
		system("cls");
		LvlUp();
		PlayerGold(Enemy.GetGold());
	}
}

void Player::BuffStop(BaseCharacter& Attacked)
{
	for (int i = 0; i < 5; i++)
	{
		if (ClassSpells[i].BufforDebuffStop >= 1)
		{
			ClassSpells[i].BufforDebuffStop--;
			if (ClassSpells[i].BufforDebuffStop == 0)
			{
				StopBufforDebuff(ClassSpells[i], Attacked);
			}
		}
		if (ClassSpells[i].CooldownTimer > 0)
		{
			ClassSpells[i].CooldownTimer--;
		}
	}
}

void Player::ManaRegeneration()
{
	if (Mana < MaxMana)
	{
		Mana += ManaRegen;
		if (Mana > MaxMana)
		{
			Mana = MaxMana;
		}
	}
}

void Player::Fight(BaseCharacter& Attacked)
{
	Attack(Attacked);

	BuffStop(Attacked);
	ManaRegeneration();
	if (Attacked.Dead)
	{
		PlayerKilledgMonster++;
		AllKilledMonsters++;
	}

}





