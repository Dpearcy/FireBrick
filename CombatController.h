#pragma once
#include "file needed.h"
#include "Player.h"
class CCombatController //// This class  is for the combat controller.
{
private:
	const enum ETypes //// This  stores the  dirrerent types of  a card.
	{
		Basic_Minion, Fireball, Lightning, Bless, Minion_Vamprie, Minion_Wall, Minion_Horde, Minion_Trample,
		Minion_Leech, Equipment_sword, Equipment_Armour
	};
	ETypes ETheType;//// This is used to work out the type of card  on the table.
	int mNumberOfCardsToDrawToTable; //// This is used to place in right place.
	int mAttackReming; //// This is used for the temple minion.
	int mOgrainalAttack; //// This holds the oragainal  attack for the temple minion.  
	int cardtype; //// This is used to work out the card type.
	CCard* Card; /// This stores the card for when moving oit from the hand to the table.
	bool mIsWallPlayer1 = false; //// This checksif their is a wall card the sorrcess side.
	bool mIsWallPlayer2 = false; //// This checks if their us a wall card the wizard side. 
public:
	CCard* mTable[30];//// This is where the cards that  will be called are.
	CCombatController(int Player);//// This creates  the instance for the combat controller.
	CCombatController(); //// This the defult constuer forthe combat contorller. 
	~CCombatController();//// This deletes the instance for the combat controller.
	virtual void getingType(CPlayer* Name, CCombatController* combatcontroller, int Attacker, CPlayer* otherPlayer);//// This works out the type of the card given  and calls the combat controller.
	virtual void hitCombat();//// This is the defcult function for  combat hit.
	int getCardOnTable(int number); //// This reutrns the location of the card on the table.
	void SetcardOnTable(CCard* card, CPlayer* Name, int& Attacker);//// This sets the the card that is selected  to the table.
	int DrawToTable(CPlayer* Name); //// This returns the  starting point of the card for each player.
	 virtual void attack(CPlayer* player, int number, int attacker, CPlayer* otherPlayer, int NumberOfAttack);//// This runs the attack for the basic minion and trample minion.
	 int AttackFromTable(CPlayer* Name);//// This returns the location of the start of the  other player's card points.
	 int Getcardtype(int number); //// This returns the card  given  type  to be used  by the combat controller.
	 bool GetIsWall(CPlayer* Player); //// This returns  if the is a wall card.
	 void SetIsWall(bool yes, CPlayer* Player); /// this set when the wall card is called.
};