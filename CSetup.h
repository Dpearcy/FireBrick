#pragma once
#include "CombatController.h"
class CSetup //// This sets up the table and asks the user if they want to shuffle.
			 //// the class also setup the  combat controller used  for the  combat in the attack phase. 
{
private:
	CCombatController* pCombatControllerStarter;//// This is the place holder for the combat controller.
public:
	CSetup(); //// This creates an instance of the combat controller.
	~CSetup();//// This deletes the instance of the combat controller. 
	CCombatController* GetCombatController();//// This returns the  combat controller back to the game manager to be used  later in the game 
};

