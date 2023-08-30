#pragma once
#include "BaseCharacter.h"


class Spells;
class Player:public BaseCharacter
{
public:
	Player();
	
	void LvlUp();
	char Action();
	void UseHealthPotion();
	int GetPlayerLVL() { return LVL; };

	//TODO Heal move to BaseCharacter and Do normal Heal for all character
	void Heal( int heal);

	//Do latter
	void  Doodge(BaseCharacter& Enemy, BaseCharacter& Player);
	void ChooseClass();
	int PlayerGold(int TakedGold);

	void CheckPlayerStatus();
	virtual void Fight(BaseCharacter& Attacked);

	virtual void BufforDebuff( BaseCharacter& Attacked);
	virtual void StopBufforDebuff(Spells& Spell, BaseCharacter& Attacked);
	virtual void AttackedSpell(Spells& Spell, BaseCharacter& Attacked);


	void Lose();
	void Win(BaseCharacter& Enemy);
	
private:
	int BaseHP;
	int MaxHp;
	int DoodgeChance;
	int DoodgeScale;
	int HealPotion;
	int HealPotionScale;
	int MonsterToLVLUp;
	int PlayerKilledgMonster;
	int AllKilledMonsters;
	int Mana;
	int MaxMana;
	int ManaRegen;
	std::string Class;
	Spells ClassSpells[5];
	Spells PlayerSpell[5];
	
	
	

	int TemporaryDamage;
	int TemporaryDoodge;
	int TemporaryHP;



	void BuffStop(BaseCharacter& Attacked);

	void ManaRegeneration();


	
};
