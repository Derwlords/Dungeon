#include "Items.h"



Items::Items(ItemType type, int price):
    type(type)
{
    SetPrice(price);
}

ItemType Items::GetType() const
{
    return type;
}

int Items::GetPrice() const
{
    return price;
}

void Items::SetPrice(int newPrice)
{
    price = newPrice;
}

void Items::ApplyBuff()
{
}
