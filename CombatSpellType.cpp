#include "stdafx.h"
#include "file needed.h"
#include "combatSpellTypes.h"
using namespace std;
CSpell::CSpell(CCombatController* &combatcontrollerOriginal)
{
	pCombatControllerCopy = new CCombatController();
	pCombatControllerCopy = combatcontrollerOriginal;
}
void CSpell::hitCombat(CPlayer* player, int attacker, CPlayer* otherPlayer, CCombatController* CombatControllerOriginal)
{
	numberToCast = pCombatControllerCopy->getCardOnTable(pCombatControllerCopy->AttackFromTable(player));
	if (pCombatControllerCopy->GetIsWall(player))
	{
		while (pCombatControllerCopy->mTable[numberToCast]->getCardType() != 6)
		{ 
			numberToCast++;
		}
		attack(player, numberToCast, attacker, otherPlayer, CombatControllerOriginal);
	}
	else attack(player, player->Random(numberToCast), attacker, otherPlayer, CombatControllerOriginal);
	return;
}
void CSpell::attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, CCombatController* &CombatControllerOriginal)
{
	int i = CombatControllerOriginal->mTable[attacker]->getCardType();
	i = i - 2;
	switch (i)
	{
	case CSpell::fireBall://fireball  3 dam . target at random   player must be higher then minons  
		cout << endl;
		CombatControllerOriginal->mTable[attacker]->outPutCardName();
		cout << " Casts Fireball ";
		CombatControllerOriginal->mTable[number]->outPutCardName();
		cout << ": ";
		CombatControllerOriginal->mTable[number]->setCardHealth(CombatControllerOriginal->mTable[number]->getCardHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack());
		if (CombatControllerOriginal->mTable[number]->getCardHealth() <= eplion)
		{
			CombatControllerOriginal->mTable[number]->outPutCardName();
			cout << "killed";
		}
		else
			cout << ".  [0]", CombatControllerOriginal->mTable[number]->outPutCardName(); cout << " health now " << CombatControllerOriginal->mTable[number]->getCardHealth();
		break;
	case CSpell::Lightning://lightning 1  dan all target.
		cout << endl;
		CombatControllerOriginal->mTable[attacker]->outPutCardName();
		cout << " Casts Lightning  on all cards and " << otherPlayer->GetPlayerName();
		for (int i = 0; i > 30; i++)
		{
			if (CombatControllerOriginal->mTable[i]->getCardType() != 13 && i != attacker)
			{
				CombatControllerOriginal->mTable[i]->setCardHealth(CombatControllerOriginal->mTable[i]->getCardHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack());
				cout << ". ", CombatControllerOriginal->mTable[i]->outPutCardName(); cout << " health now " << CombatControllerOriginal->mTable[i]->getCardHealth();
			}	
		}
		otherPlayer->setPlayerhealth(otherPlayer->GetplayerHealth() - CombatControllerOriginal->mTable[attacker]->getCardAttack());
		break;
	case CSpell::Bless://bless target at random all enemy chosen  attacks  by  2  firendly  chosen  health + 2. 
		cout << endl;
		CombatControllerOriginal->mTable[attacker]->outPutCardName();
		cout << " Casts Bless ";
		number =  player->Random(CombatControllerOriginal->AttackFromTable(player));
		number = player->Random(2);
		number = player->Random(CombatControllerOriginal->DrawToTable(player));
		if (number > 0 && number < 10)
		{
			CombatControllerOriginal->mTable[number]->setCardHealth(CombatControllerOriginal->mTable[number]->getCardHealth() + CombatControllerOriginal->mTable[attacker]->getCardHealth());
		}
		else if (number > 20 && number < 29)
		{
			CombatControllerOriginal->mTable[number]->setCardHealth(CombatControllerOriginal->mTable[number]->getCardHealth() + CombatControllerOriginal->mTable[attacker]->getCardHealth());
		}
		else  	number = player->Random(CombatControllerOriginal->AttackFromTable(player));
		number += player->Random(CombatControllerOriginal->DrawToTable(player));
		break;
	}
}
CSpell::~CSpell()
{
	//delete(pCombatControllerCopy);
}