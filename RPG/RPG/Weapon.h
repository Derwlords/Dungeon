#pragma once
#include "Items.h"


class Weapon : public Items {
public:
    Weapon(ItemType type, int price, int damage, int mana, int cooldownReduction);
    int GetDamage() const;
    int GetMana() const;
    int GetCooldownReduction() const;
    virtual void ApplyBuff() override;

private:
    int price;
    int damage;
    int mana;
    int cooldownReduction;
};
