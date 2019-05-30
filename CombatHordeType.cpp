#include "stdafx.h"
#include "file needed.h"
#include "CombatHordeType.h"
using namespace std;
CHorde::CHorde(CCombatController* &CombatControllerOriginal)
{
	pCombatControllerCopy = new CCombatController(1);
	pCombatControllerCopy = CombatControllerOriginal;
}
void CHorde::hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal)
{
	numberToAttack = CombatControllerOriginal->AttackFromTable(player);
	if (CombatControllerOriginal->GetIsWall(player))
	{
		while (CombatControllerOriginal->mTable[numberToAttack ]->getCardType() != 6)
		{
			numberToAttack++;
		}
		attack(player, numberToAttack, attacker, otherPlayer, CombatControllerOriginal);
	}
	else attack(player, player->Random(numberToAttack), attacker, otherPlayer ,CombatControllerOriginal);

	return;
}
void CHorde::attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal)
{
	
	for (int i = 20; i < 30; i++)
	{
			if (CombatControllerOriginal->mTable[i]->getCardType() == 7)
			{
				if (i == attacker)
				{
					i++;
				}
				numberOfRats++;
				CombatControllerOriginal->mTable[attacker]->setCardAttack(CombatControllerOriginal->mTable[attacker]->getCardAttack() + numberOfRats);
			}

	}
	cout << endl;
	CombatControllerOriginal->mTable[attacker]->outPutCardName();
	cout << " attacks ";
	CombatControllerOriginal->mTable[number]->outPutCardName();
	CombatControllerOriginal->mTable[number]->setCardHealth(CombatControllerOriginal->mTable[number]->getCardHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack());
	if (CombatControllerOriginal->mTable[number]->getCardHealth() <= eplion)
	{
		cout << " killed: ";
		CombatControllerOriginal->mTable[number]->setCardType(13);
	}
	else { cout << ". ", CombatControllerOriginal->mTable[number]->outPutCardName(); cout << " health now " << CombatControllerOriginal->mTable[number]->getCardHealth(); }
}
CHorde::~CHorde()
{
	//delete(pCombatControllerCopy);
}