#include "Spells.h"



Spells::Spells(std::string SpellName, bool Self, int BufforDebaf, int ManaCost, int Cooldown, int DurBufforDebuff, TypeSpell SpellType)
	:SpellName(SpellName), Self(Self), BufforDebaf(BufforDebaf), ManaCost(ManaCost),
	Cooldown(Cooldown), DurBufforDebuff(DurBufforDebuff), SpellType(SpellType)
{
	CooldownTimer = 0;
}






const Spells& Spells::operator()(std::string SpellName, bool Self, int BufforDebaf, int ManaCost, int Cooldown, int DurBufforDebuff, TypeSpell SpellType)
{
	return(Spells(SpellName, Self, BufforDebaf, ManaCost, Cooldown, DurBufforDebuff,SpellType));
}




