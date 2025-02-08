#pragma once

#include <string>

enum class ItemType {
    Ring,
    Chestplate,
    Boots,
    Helmet,
    Weapon
};


class Items {
public:
    Items(ItemType type, int price);
    virtual ~Items() = default;

    ItemType GetType() const;
    int GetPrice() const;
    void SetPrice(int newPrice);

    virtual void ApplyBuff(); 

private:
    ItemType type;
    int price;
};



