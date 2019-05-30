#pragma once
#include "card.h"
#include "file needed.h"

using namespace std;
class CCombatController;///This class is made later in the combatcontorller .h file
class CPlayer //// This class is  used the player  to hold the hand  run phases in a  round. 
{
private:
	int mHealth;//// This  is the health of the player. 
	CCard* mpHand[2];//// This is the hand that uses the card. 
	int mPlayerID;//// This is the player id that is used for combat controller.
	int mNumberOfCardsToDraw = eplion; /// this is used for the  placement of the card in the hand.
	unique_ptr <CCard> mpTmp; //// This is used to draw from the deck to the hand.
	int mNumberOfCardToAttack;//// This is used to hold the  number of the card that will attack.
	int mAttacker; //// This holds the number of the atttacker.
	string mName; //// This holds the name of the player.
	bool mIsDefended; //// This holds if the player is protected by armour.
	int mTimer = 0; //// This records the number of hits for the armour and removes the armour atfer.
public:
	CPlayer(int number);//// This craates the instance of the hand used to draw to the table.
	~CPlayer();//// This deteles the instance of the hand and  player class.
	int GetplayerHealth();//// This returns the health of the player used at the end of  each round.
	string GetPlayerName(); //// This gets name of the for the class.
	void setIsDefended(bool yes); ////This sets wherether the  player is defended.
	void setPlayerhealth(int number); //// This sets the player health, This is used when you hit the player.
	int FindCardtype(int number);//// This return the   card type   so the combat controller  know the type of the card given.
	 void Draw(deque < unique_ptr <CCard>>& deck, CPlayer* player1);//// This  takes the two top cards from the deck and places them in the  hand.
	 void Rest();//// This is used to slow the round down  by resting  for a few seconds.
	 void depoly(CPlayer* player, CPlayer* player2, CCombatController* combatController);//// This places the card  on the top  from the hand to the  table  to use be used in the attack phase.
	 void attack(CPlayer* Player, CPlayer* player2, CCombatController*  combatController);//// This is where the  card type is found and the combat is called to  attack the other cards.
	 void Endturn();/// This ends the turn but also  checks the health  of the player  and the current round. 
	 int GetPlayerID(); //// This return the player id so the  combat controller knows the player id.
	 void killplayer() { mHealth = eplion; }//// used for  debuging.
	 bool checkingHealth(CPlayer* Name );//// This checks  the health  for the  player to see if the player is at zero.
	int Random(const int n) ////This is the random function given by Gareth Bellaby.
	{	
		return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
	}
};