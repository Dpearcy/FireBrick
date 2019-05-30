#include "stdafx.h"
#include "file needed.h"
#include "combatEquipmentType.h"
using namespace std;
CEquipment::CEquipment(CCombatController* &CombatControllerOriginal)
{
	pCombatControllerCopy = new CCombatController(1);
	pCombatControllerCopy = CombatControllerOriginal;
	
}
void CEquipment::hitCombat(CPlayer* player, int attacker , CPlayer* otherPlayer, CCombatController* CombatControllerOriginal)
{
	numberToEquip = CombatControllerOriginal->getCardOnTable(CombatControllerOriginal->AttackFromTable(player));
	attack(player, player->Random(numberToEquip), attacker , otherPlayer , CombatControllerOriginal);
	return;
}
void CEquipment::attack(CPlayer* player ,int number, int attacker, CPlayer* otherPlayer , CCombatController* &CombatControllerOriginal)
{	
	cout << endl;
	CombatControllerOriginal->mTable[attacker]->outPutCardName();
	if (CombatControllerOriginal->Getcardtype(attacker) == 10)
		{
		CombatControllerOriginal->mTable[attacker]->setCardType(13);
			if (CombatControllerOriginal->getCardOnTable(CombatControllerOriginal->DrawToTable(player)) == 31)
				{ 
			cout << " player health goes up by 2";
			player->setPlayerhealth(player->GetplayerHealth() + 2);
				}
			else
				{
					cout << " incresse it's attack  by 2";
					CombatControllerOriginal->mTable[attacker]->setCardAttack(CombatControllerOriginal->mTable[attacker]->getCardAttack() + 2);
				}
				
		}
	else
		{
		CombatControllerOriginal->mTable[attacker]->setCardType(13);
			if (CombatControllerOriginal->getCardOnTable(CombatControllerOriginal->DrawToTable(player)) == 31)
			{
				cout << " adds protection to" << player->GetPlayerName();
				player->setIsDefended(1);
			}
			else
			{
				cout << " adds protection to  ";
				CombatControllerOriginal->mTable[number]->outPutCardName();
				CombatControllerOriginal->mTable[number]->setBoolDefended(1);
			}
			
		}
	
	


}
CEquipment::~CEquipment()
{
	//delete(pCombatControllerCopy);
}