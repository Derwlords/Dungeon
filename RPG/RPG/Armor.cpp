#include "Armor.h"

Armor::Armor(ItemType type, int price, int defense, int hp, int agility):
Items(type, price)
{
}

int Armor::GetDefense() const
{
    return 0;
}

int Armor::GetHP() const
{
    return 0;
}

int Armor::GetAgility() const
{
    return 0;
}

void Armor::ApplyBuff()
{
}
