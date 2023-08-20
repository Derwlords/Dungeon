#pragma once
#include "iostream"
#include "string.h"

enum TypeSpell
{
	eHeal,
	eDamageUp,
	eDoodgeUp,
	eDebuffAttack,
	eDbuffHP,
	eAttackedSpell,
	eMaxSpell

};
class Spells
{
public:
	Spells(std::string SpellName = "No", bool Self = false, int BufforDebaf = 0, int ManaCost = 0, int Cooldown = 0,int DurBufforDebuff = 0, TypeSpell SpellType = eMaxSpell);

	const Spells& operator()(std::string SpellName = "No",
		bool Self = false, int Buff = 0,
		int ManaCost = 0, int Cooldown = 0, 
		int DurBufforDebuff = 0,
		TypeSpell SpellType = eMaxSpell) ;
	

	

	public:
	std::string SpellName;
	bool Self;
	int BufforDebaf;
	int ManaCost;
	int Cooldown;
	int CooldownTimer;
	int DurBufforDebuff;
	int BufforDebuffStop;
	TypeSpell SpellType;
};
