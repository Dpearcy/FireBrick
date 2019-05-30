#include "stdafx.h"
#include "combatbasictype.h"
#include "file needed.h"
#include "Player.h"
using namespace std;
CBasicType::CBasicType(CCombatController* &combatcontrollerOriginal)
{
	pCombatControllerCopy = new CCombatController(1);
	pCombatControllerCopy = combatcontrollerOriginal;
}
void  CBasicType::hitCombat(CPlayer* player , int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal)
{
	numberToAttack = pCombatControllerCopy->getCardOnTable(pCombatControllerCopy->AttackFromTable(player)); 
	if (pCombatControllerCopy->GetIsWall(player))
	{
		while (pCombatControllerCopy->mTable[numberToAttack ]->getCardType() != 6)
		{
			numberToAttack++;
		}
		pCombatControllerCopy->attack(player, numberToAttack , attacker, otherPlayer, numberToAttack);
	 }
	else pCombatControllerCopy->attack(player, player->Random(numberToAttack), attacker , otherPlayer, numberToAttack);
	
	
	 return;////this hits the other player cards.  
}
CBasicType::~CBasicType()
{
	//delete(pCombatControllerCopy);
}