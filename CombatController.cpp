#include "stdafx.h"
#include "file needed.h"
#define KIll
#include "CombatController.h"
#include "combatbasictype.h"
#include "combatEquipmentType.h"
#include "combatSpellTypes.h"
#include "CombatHealType.h"
#include "combatShieldType.h"
#include "CombatHordeType.h"
using namespace std;
CCombatController::CCombatController()
{}
CCombatController::CCombatController(int Player)
{
	for (int i = eplion; i < 30; i++)
	{
		mTable[i] = new CCard;
		mTable[i]->setCardType(13);
		
	}
	Card = new CCard;
	if (Player == 1)
	{
		mNumberOfCardsToDrawToTable = eplion;
	}
	else mNumberOfCardsToDrawToTable = 20;
}
 int CCombatController::DrawToTable(CPlayer* Name)
{
	 if (Name->GetPlayerID() == 1)
	 {
		  return eplion;
	 }
	 else return 20;
}
 int CCombatController::AttackFromTable(CPlayer* Name)
 {
	 if (Name->GetPlayerID() == 2)
	 {
		 return eplion;
	 }
	 else return 20;
 }
CCombatController::~CCombatController()
{
}
 void CCombatController::getingType(CPlayer* Name, CCombatController* combatcontroller, int Attacker, CPlayer* otherPlayer)
 {
	 cardtype = 0; //// This is used to work out the card type.
	 Attacker = DrawToTable(Name);
	while (cardtype != 12)
	{ 
	 cardtype = combatcontroller->Getcardtype(Attacker);
	 cardtype = cardtype  - 1;
	 switch (cardtype)
	 {
	 case(Basic_Minion) :
	 case (Minion_Trample):
		{
		 CCArdType* pBasicMinion = new CBasicType(combatcontroller);
		 pBasicMinion->hitCombat(Name,Attacker,otherPlayer,combatcontroller);
		 combatcontroller = combatcontroller;
		 delete(pBasicMinion);
		 break;
		}
	 case (Fireball):
	 case (Lightning):
	 case (Bless):		{
		 CCArdType* pSpell = new CSpell(combatcontroller);
		 pSpell->hitCombat(Name, Attacker, otherPlayer,combatcontroller);
		delete(pSpell);
		 break;
		}	
	case(Minion_Wall):
		{
		CCArdType* pShield = new CShield(combatcontroller);
		pShield->hitCombat(Name, Attacker, otherPlayer, combatcontroller);
		delete(pShield);
		break;/// must attack  
		}
	case(Minion_Horde):
		{
		CCArdType* pHorde = new CHorde(combatcontroller);
		pHorde->hitCombat(Name, Attacker, otherPlayer, combatcontroller);
	 	delete(pHorde);
		break; /// more the same cards higher attack 
		}
	case (Minion_Vamprie):////The vamprie is like basic minion but heals itself and end of attack.		  
	case(Minion_Leech)://// The Leech attacks normal but takes attack given and gives it to player.
		{
		CCArdType* Vampire = new CVampire(combatcontroller);
		Vampire->hitCombat(Name, Attacker, otherPlayer,combatcontroller);
		delete(Vampire);
		break;
		}
	case(Equipment_Armour):
	case (Equipment_sword):
		{
		CCArdType* Equipment = new CEquipment(combatcontroller);
		Equipment->hitCombat(Name, Attacker, otherPlayer,combatcontroller);
		delete(Equipment);
		break;
		}
	 }
	Attacker++;
	}
 } 
 void CCombatController::hitCombat()
 {
	 cout << "ERROR wrong class function  check  using right function hahahahahahahahhahahaha/n";
	 return;
 }
 void CCombatController::attack(CPlayer* player,int number ,  int attacker, CPlayer* otherPlayer, int numberOfAttack)
 {	
		mAttackReming = mTable[number]->getCardHealth() - mTable[attacker]->getCardAttack();
	 cout << endl;
	 mTable[attacker]->outPutCardName();
	 cout << " attacks ";
	 if (numberOfAttack == 31)
	 {
		 otherPlayer->setPlayerhealth((otherPlayer->GetplayerHealth() - mTable[attacker]->getCardAttack()) );
		 cout << otherPlayer->GetPlayerName() << ": " << otherPlayer->GetPlayerName() << " "  << otherPlayer->GetplayerHealth();

	 }	
	 else
	 {
		 mTable[number]->outPutCardName();

				
		mTable[number]->setCardHealth(mTable[number]->getCardHealth() - mTable[attacker]->getCardAttack()); 
	
			 if ( mTable[number]->getCardHealth() <= eplion)
				 {
					 
					 cout << " killed:";
					 mTable[number]->setCardType(13); 
					 if (mTable[attacker]->getCardType() == 8)
						 {
						 mOgrainalAttack = mTable[attacker]->getCardAttack();
								while (mTable[attacker]->getCardAttack() != eplion)
									{
										mAttackReming = mTable[number]->getCardHealth() - mTable[attacker]->getCardAttack();
										number = getCardOnTable(AttackFromTable(player));
										attack(player, player->Random(number), attacker, otherPlayer,numberOfAttack);
										mTable[attacker]->setCardAttack(mTable[attacker]->getCardAttack() - mAttackReming);
									}
								mTable[attacker]->setCardAttack(mOgrainalAttack);
						 } 
						 mTable[number]->setCardType(13);
		 
			 }
			 else { cout << ".", mTable[number]->outPutCardName(); cout << " health now " << mTable[number]->getCardHealth(); }
	 }
 }
 int CCombatController::getCardOnTable(int number)
 {
	 for (int i = number ; i < 30; i++)
	 {
		 if (mTable[i]->getCardType() != 13)
		 {
			return i;
			break;
		 }
	 }
	 return  31;
 }
 int CCombatController::Getcardtype(int number)
 {
	return mTable[number]->getCardType();
 }
 void CCombatController::SetcardOnTable(CCard* card, CPlayer* Name , int& Attacker)
 {
	 if (Name->GetPlayerID() == 1)
	 {
		 mNumberOfCardsToDrawToTable = DrawToTable(Name);
		 while (mTable[mNumberOfCardsToDrawToTable]->getCardType() != 13)
		 {
			 mNumberOfCardsToDrawToTable++;
		 }
		 mTable[mNumberOfCardsToDrawToTable] = card;
		 mTable[mNumberOfCardsToDrawToTable]->outPutCardName();
		 cout << "(" << mTable[mNumberOfCardsToDrawToTable]->getCardHealth() << ")";
		 Attacker = mNumberOfCardsToDrawToTable;
		 mNumberOfCardsToDrawToTable++;
		 Card = card;
	 }
	 else if (Name->GetPlayerID() == 2)
	 {
		 mNumberOfCardsToDrawToTable = DrawToTable(Name);
		 while (mTable[mNumberOfCardsToDrawToTable]->getCardType() != 13)
		 {
			 mNumberOfCardsToDrawToTable++;
		 }
		 mTable[mNumberOfCardsToDrawToTable] = card;
		 mTable[mNumberOfCardsToDrawToTable]->outPutCardName();
		 cout << "(" << mTable[mNumberOfCardsToDrawToTable]->getCardHealth() << ")";
		 Attacker = mNumberOfCardsToDrawToTable;
		 mNumberOfCardsToDrawToTable++;
		 Card = card;
	 }
 }
 bool CCombatController::GetIsWall(CPlayer* Player)
 {
	 if (Player->GetPlayerID() == 1)
	 {
		 return mIsWallPlayer2;
	 }
	 else return mIsWallPlayer1;
 }
 void CCombatController::SetIsWall(bool yes, CPlayer* Player)
 {
	 if (Player->GetPlayerID() == 1)
	 {
		  mIsWallPlayer1  = yes;
	 }
	 else  mIsWallPlayer2 = yes;
 }