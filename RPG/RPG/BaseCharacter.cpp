#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
	Dead = false;
}



void BaseCharacter::Attack(BaseCharacter& Attacked)
{
	UI();
	std::cout << symbol << " attack " << Attacked.symbol << "\nAnd dealt: " << Damage << " damage\n";
	Attacked.HP -= Damage;
	if (Attacked.HP <= 0)
	{
		Attacked.HP = 0;
		std::cout << Attacked.Name << " has " << " Dead\n";
		Attacked.Dead = true;
	}
	else
	{
		std::cout << Attacked.Name << " has " << Attacked.HP << " HP left\n\n\n";
	}
}








//void BaseCharacter::Heal(BaseCharacter& Character,int heal)
//{
//	std::cout << "Character heal " << heal << std::endl;
//	Character.HP += heal;
//	if (Character.HP < MaxHP)
//	{
//		Character.HP = MaxHP;
//	}
//}

void BaseCharacter::UI()
{
	std::cout << std::endl;
	for (int i = 0; i < 50; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}

