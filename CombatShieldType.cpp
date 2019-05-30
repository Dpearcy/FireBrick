#include "stdafx.h"
#include "file needed.h"
#include "combatShieldType.h"
using namespace std;
CShield::CShield(CCombatController* &combatcontrollerOriginal)
{
	pCombatControllerCopy = new CCombatController(1);
	pCombatControllerCopy = combatcontrollerOriginal;
}

void CShield::hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal)
{
	numberToAttack = CombatControllerOriginal->getCardOnTable(CombatControllerOriginal->AttackFromTable(player));
	attack(player, numberToAttack, attacker, otherPlayer ,CombatControllerOriginal);
	return;
}
void CShield::attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal)
{
	if (CombatControllerOriginal->mTable[attacker]->getCardAttack() > eplion)
	{
			cout << endl;
			CombatControllerOriginal->mTable[attacker]->outPutCardName();
			cout << " attacks ";
			CombatControllerOriginal->mTable[number]->outPutCardName();
			cout << ": ";
			CombatControllerOriginal->mTable[number]->setCardHealth(CombatControllerOriginal->mTable[number]->getCardHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack());
			if (CombatControllerOriginal->mTable[number]->getCardHealth() <= eplion)
			{
				CombatControllerOriginal->mTable[number]->outPutCardName();
					cout << "killed";
			}
			else cout << ". ", CombatControllerOriginal->mTable[number]->outPutCardName(); cout << " health now " << CombatControllerOriginal->mTable[number]->getCardHealth();
	}


}
CShield::~CShield()
{
	//delete(pCombatControllerCopy);
}