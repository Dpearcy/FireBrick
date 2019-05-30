#pragma once
//#include "CombatController.h"
#include "combatbasictype.h"
class CEquipment : public CCArdType
{
private:
	CCombatController* pCombatControllerCopy;//// This holds the combat controller given by the  game manager.
	int numberToEquip;//// This is used to hold the   number  that the equipment card will be asgined to.
public:
	CEquipment(CCombatController* &combatcontrollerOriginal);//// This crates an instance of the 
	void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal);//// This gets the card, the equipment will be equiped to a card 
											////if not is on table it will applyed to the player. 
	void attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal);//// This equips the  armour  or sword to a card.
	~CEquipment();/// This deletes the instance of the class.

};
