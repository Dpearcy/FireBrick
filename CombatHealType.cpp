#include "stdafx.h"
#include "file needed.h"
#include "CombatHealType.h"
using namespace std;
CVampire::CVampire(CCombatController* &combatcontrollerOriginal)
{
	pCombatControllerCopy = new CCombatController(1);
	pCombatControllerCopy = combatcontrollerOriginal;
}
void CVampire::hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal)
{
	numberToAttack = CombatControllerOriginal->getCardOnTable(CombatControllerOriginal->AttackFromTable(player));
	if (CombatControllerOriginal->GetIsWall(player))
	{
		while (CombatControllerOriginal->mTable[numberToAttack ]->getCardType() != 6)
		{
			numberToAttack++;
		}
		attack(player, numberToAttack, attacker, otherPlayer, CombatControllerOriginal);
	}
	else attack(player, player->Random(numberToAttack), attacker, otherPlayer, CombatControllerOriginal);
	return;
}
void CVampire::attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal)
{
	cout << endl;
	CombatControllerOriginal->mTable[attacker]->outPutCardName();
	cout << " attacks ";
	CombatControllerOriginal->mTable[number]->outPutCardName();
	CombatControllerOriginal->mTable[number]->setCardHealth(CombatControllerOriginal->mTable[number]->getCardHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack());
	if (CombatControllerOriginal->mTable[number]->getCardHealth() <= eplion)
	{
		cout << "killed:";
	}
	else cout << ". ", CombatControllerOriginal->mTable[number]->outPutCardName(); cout << " health now " << CombatControllerOriginal->mTable[number]->getCardHealth();
	if (CombatControllerOriginal->mTable[attacker]->getCardType() == 9)
	{
		player->setPlayerhealth(player->GetplayerHealth() + abs(CombatControllerOriginal->mTable[number]->getCardHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack()));
	}
	else  CombatControllerOriginal->mTable[attacker]->setCardHealth(CombatControllerOriginal->mTable[attacker]->getCardHealth() + 1);
}
CVampire::~CVampire()
{
	//delete(pCombatControllerCopy);
}