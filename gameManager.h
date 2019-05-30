#pragma once
#include "Player.h"
#include "file needed.h"
using namespace std;

class CGameManager////This class controls all the game and The player. 
{
private:
	int mNumberOfRounds; //// This is the total number of rounds in the game. 
	int mCurrentRound;//// THis is the current round of the game. 

	CPlayer* pSorceress;//// This holds the player and the player's hand for the soreress. 
	CPlayer* pWizard;//// This holds the player and the  player's hand for the wizard.
	CCombatController* pCombatController;
	deque <unique_ptr <CCard > > pSorceressDeck;//// This is the main sorceress deck used by the manager to hold all the sorercess cards.
	deque <unique_ptr <CCard > > pWizardDeck;//// This is the main wizard deck used by the manager to hold all the wizard cards.
public:
	CGameManager(); //// this creates an instance for the manager and  sets the number of rounds.
	~CGameManager();//// This deletes the instance of the manager and deletes the main decks and table.
	CPlayer* makePlayers(int player ); //// This creates the instance for the players and sortes them in the sorceress and wizard varables. 
	void runRound(CPlayer* player1, CPlayer* Player2,CGameManager* GameManager);//// This runs the round  and calls the combat controller when needed. 
	void playRound(CPlayer* player1, CPlayer* Player2, CGameManager* GameManager, deque < unique_ptr <CCard>>& sorceressDeck,
	deque < unique_ptr <CCard>>& wirardDeck, CCombatController* combatContorller);//// This check if it is the first round and then creates  an instance of the  setup and then calls it.
	void gameShutdown(CGameManager* GameManager);//// This  only runs if the player health is at zero, This deletes all remaining varables and closes the program.
	void loadFiles();//// This creates an instance of the loadfile class and  calls it and then  returns the  decks  for the sorceress and wizard. 
};