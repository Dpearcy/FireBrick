#pragma once
//#include "CombatController.h"
#include "CombatType.h"
class CSpell : public CCArdType
{
private:
	CCombatController* pCombatControllerCopy;//// This holds the combat controller given by the  game manager.
	int numberToCast; //// The  number of the card cast the spell to.
	enum ESpells { fireBall, Lightning, Bless}; //// This is the spells used working out the spell. 
	ESpells spell;//// an instane if the spells that can be used.
public:
	CSpell(CCombatController* &combatcontrollerOriginal); ///// This creates an instnace of the  Fireball
	void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal);//// This gets the card, the spell is cast on a card or player in the attack phese. 
	void attack(CPlayer* player,int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal);//// This is used to cast the spells  fireball, lightning maybe bless.
	~CSpell();/// This deletes the instance of the class.
};
