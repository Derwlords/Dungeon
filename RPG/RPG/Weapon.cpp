#include "Weapon.h"

Weapon::Weapon(ItemType type, int price, int damage, int mana, int cooldownReduction):
Items(type, price)
{
	
}



int Weapon::GetDamage() const
{
	return 0;
}

int Weapon::GetMana() const
{
	return 0;
}

int Weapon::GetCooldownReduction() const
{
	return 0;
}

void Weapon::ApplyBuff()
{
}
