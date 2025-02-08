#pragma once
#include "Items.h"


class Armor : public Items {
public:
    Armor(ItemType type, int price, int defense, int hp, int agility);
    int GetDefense() const;
    int GetHP() const;
    int GetAgility() const;

    virtual void ApplyBuff() override;

private:
    int defense;
    int hp;
    int agility;
};