#pragma once
#include"CombatController.h"
class CCArdType
{
public:
	virtual void hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal) = 0;//// This is the defcult function for  combat hit.

};

