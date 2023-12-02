#pragma once
#include "iostream"
#include "string.h"
#include "Spells.h"
class BaseCharacter
{
public:
	BaseCharacter();

	


	virtual void Fight( BaseCharacter& Attacked) = 0;
	void Attack(BaseCharacter& Attacked);
	virtual void BufforDebuff( BaseCharacter& Attacked) = 0;
	virtual void StopBufforDebuff(Spells& Spell, BaseCharacter& Attacked) = 0;
	virtual void AttackedSpell(Spells& Spell, BaseCharacter& Attacked) = 0;

	bool Dead;


	void SetHealth(int Damage) { HP -= Damage; }


	bool GetStatus() { return Dead; }

	int GetGold() { return Gold; }

	int GetHealth() { return HP; }

	std::string GetName() { return Name; }

	char GetSymbol() { return symbol; }

protected:
	std::string Name;
	char symbol;
	int HP;
	int HpScale;
	int Damage;
	int DamageScale;
	int LVL;
	int Gold;
	
	
protected:

	void UI();

private:
	
};
