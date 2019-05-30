#pragma once

//#include "CombatController.h"
#include "CombatType.h"
class CHorde : public CCArdType
{
private:
	CCombatController* pCombatControllerCopy;//// This holds the combat controller given by the  game manager.
	int numberToAttack;///The number of the card that will be attacked on the table.
	int numberOfRats;//// The number of rats on the table.
public:
	CHorde(CCombatController* &CombatcontrollerOriginal);//// This crates an instance of the 
	void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal);//// This gets the card, the horde will check to see if other 
																		////horde cards  are  on the card. 
	void attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal);//// This equips the  armour  or sword to a card.
	~CHorde();/// This deletes the instance of the class.
};