#pragma once
//#include "CombatController.h"
#include "CombatType.h"
class CVampire : public CCArdType
{
private:
	CCombatController* pCombatControllerCopy;//// This holds the combat controller given by the  game manager.
	int numberToAttack; /// Ths number of the card to  attack on the table.
public:
	CVampire(CCombatController* &combatControllerOriginal);
	void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal);//// This gets the card, the vampire and leech will hit and then run 
	//the  hit on the card that is returned from the random function. It  ether  heals itself or  gives  health to player. 
	void attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal); //// This used for the vampire and leech
	~CVampire();/// This deletes the instance of the class.
};
