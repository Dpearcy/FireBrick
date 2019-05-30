#pragma once
//#include "CombatController.h"
#include "CombatType.h"
class CShield : public CCArdType
{
private:
	CCombatController* pCombatControllerCopy;//// This holds the combat controller given by the  game manager.
	int numberToAttack;//// This holds the value of the card that will be attack  in this case it is the wall card.
public:
	CShield(CCombatController* &combatcontrollerOriginal);//// This creates  an instance  of the  class and asigns the combat controller.
	void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal); //// This works  simualr to  the  main combathit in combatcontroller 
	////but does not call the random function for the card to attack.
	void attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal); //// This used for wall as  all  targets must  hit the wall.
	~CShield();/// This deletes the instance of the class.
};
