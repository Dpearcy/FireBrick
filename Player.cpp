
#include"stdafx.h"
#include "Player.h"
#include "file needed.h"
#include "CombatController.h"
using namespace std;
CPlayer::CPlayer(int number)
{
	mHealth = 30;
	mPlayerID = number;
	mpHand[eplion] = new CCard;
	mpHand[1] = new CCard;
	if (number == 1)
	{
		mName = "Sorceress";
	}
	else mName = "Wizard";
}
CPlayer::~CPlayer()
{
	delete(mpHand[0]);
	delete(mpHand[1]);
}
int CPlayer::GetplayerHealth()
{
	return mHealth;
}
string CPlayer::GetPlayerName()
{
	return mName;
}
bool CPlayer::checkingHealth(CPlayer* Name)
{
	if (Name->GetplayerHealth() == eplion) ////This quits out of game when health is low enough.
	{
		return true;////Ths returns true if the player is died.
	}
	return false;
}
int CPlayer::FindCardtype(int number)
{
    return mpHand[number]->getCardType();
}

 void CPlayer::Draw(deque < unique_ptr <CCard>>& deck , CPlayer* player1)
 {
	 mpTmp.reset();
	 mpTmp = move(deck.front());
	 mpHand[mNumberOfCardsToDraw] = mpTmp.get();
	 deck.pop_front();
	mpHand[mNumberOfCardsToDraw]->outPutCardName();
	mNumberOfCardsToDraw++;
	mpTmp.release();
 }
 void CPlayer::Rest()
 {
	 mNumberOfCardsToDraw = 1;
	 cout << endl;
	#ifdef _DEBUG
		cout << "resting " << endl;
	#endif // _DEBUG
	 Sleep(900);
 }
 void CPlayer::depoly(CPlayer* Player, CPlayer* player2,   CCombatController* combatController)
 {
	 cout << "Cards on table ";
	 mAttacker = Player->Random(1);
	 int handNumber = mAttacker;
	 combatController->SetcardOnTable(mpHand[mAttacker], Player,mAttacker);
		 if (handNumber == eplion)
		 {
				mpHand[eplion] = mpHand[1];
				mpHand[1] = NULL;
		 }
		 handNumber = NULL;
 }
 void CPlayer::attack(CPlayer* Player, CPlayer* player2,   CCombatController* combatController )//
 {
		combatController->getingType(Player,combatController,mAttacker , player2);
 }
 void CPlayer::Endturn()
 {
	 cout << endl;
	 cout << endl;
 }
 void CPlayer::setPlayerhealth(int number)
 {
	 if (mIsDefended)
	 {
		mHealth = number + 1;
		mTimer++;
		if (mTimer > 10)
		{
			mIsDefended = false;
			mTimer = 0;
		}
	 }
	 else mHealth = number; 
 }
 int CPlayer::GetPlayerID()
 {
	 return mPlayerID;
 }
 void CPlayer::setIsDefended(bool yes)
 {
	 mIsDefended = yes;
 }