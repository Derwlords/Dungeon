#pragma once
#include "BaseCharacter.h"
#include "Player.h"
enum EnemyType
{
	Slime,
	Skelet,
	SkeletKnight,
	Zombi,
	Orc,
	Vampire,
	Minotavr,
	Dragon,
	Hydra,
	MiniBoss,
	FinalBoss,
	MaxType

};

struct Monsters
{
	int id;
	char symbol;
	std::string Name;
	int HPScale;
	int DamageScale;
	int GoldScale;
};
class Enemy :public BaseCharacter
{
public:
	Enemy();
	void MonsterGenerateon(Player& Player);
	
	
	virtual void Fight(BaseCharacter& Attacked);
	

	virtual void BufforDebuff( BaseCharacter& Attacked);
	virtual void StopBufforDebuff(Spells& Spell, BaseCharacter& Attacked);
	virtual void AttackedSpell(Spells& Spell, BaseCharacter& Attacked);

protected:
	virtual void UI() override;
private:
	int id;
	int GoldScale;

	
};

