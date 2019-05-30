#pragma once
#include "CombatType.h"
class CBasicType : public CCArdType//// This is the class  and holds the  combat control
											//// for the  basic minion  type  of card. (e.g Swordswinger or Orc) 
{
private:
	CCombatController* pCombatControllerCopy; //// This holds the  combat controller that  given  by the games manager.
	int numberToAttack;////This holds the number that used to as the  attack starter. 
public:
	CBasicType(CCombatController* &combatcontrollerOriginal);//// The creates the an instance of the  combat controller and gives it the data got from the  game manager.
	void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal); //// This gets the card, the basic minion will hit and then proforms
	///the  hit on the card that is returned from the random function. 
	~CBasicType();//// This is called when the class is deleted.
};
