#include "stdafx.h"
#include "file needed.h"
#include "gameManager.h"
#include "CFlie.h"
#include "CombatController.h"
#include "CSetup.h"
CGameManager::CGameManager()
{
	mNumberOfRounds = 30;
}

CGameManager::~CGameManager()
{
	delete(pSorceress);
	delete(pWizard);
	
}
CPlayer* CGameManager::makePlayers(int player)
{
	if (player == 1)
	{
		pSorceress = new CPlayer(1);
		return pSorceress;
	}
	else
	{
		pWizard = new CPlayer(2);
		return pWizard;
	}
	

 }
void CGameManager::loadFiles()
{
	CFile* loadfile = new CFile();
	loadfile->loadFiles();
	pSorceressDeck = loadfile->GetSorceressDeck();
	pWizardDeck = loadfile->GetWizardDeck();
#ifdef _DEBUG
	//cout << "data loaded \n";
#endif // _DEBUG
	delete loadfile;
}
void CGameManager::gameShutdown(CGameManager* GameManager)
{
	delete (GameManager);
}
void CGameManager::runRound(CPlayer* player1, CPlayer* Player2, CGameManager* GameManager)
{
	if (mCurrentRound == eplion)
	{
		mCurrentRound++;
		CSetup* New_Setup = new CSetup();
		 pCombatController =  New_Setup->GetCombatController();
		
		GameManager->playRound(player1, Player2, GameManager, pSorceressDeck,pWizardDeck,pCombatController);//// This  runs a  round  and call the combat  controller
	delete(New_Setup);
	}
}
void CGameManager::playRound(CPlayer* Player1, CPlayer* Player2, CGameManager* GameManager, deque < unique_ptr <CCard>>& sorceressDeck,
	deque < unique_ptr <CCard>>& wizardDeck ,CCombatController* combatContorller)
{
	cout << Player1->GetPlayerName() << " begins with "; Player1->Draw(sorceressDeck ,Player1);
	cout << endl;
	cout << Player2->GetPlayerName() << " begins with "; Player2->Draw(wizardDeck, Player1);
	cout << endl;
	cout << endl;
	while (mCurrentRound != mNumberOfRounds)
	{
		cout << "Round " << mCurrentRound << "\n";
		cout << Player1->GetPlayerName() << " draws ";
		Player1->Draw(sorceressDeck, Player1);//// draw 2 cards 
		Player1->Rest();
		Player1->depoly(Player1 ,Player2,combatContorller);
		Player1->attack(Player1 , Player2, combatContorller);
		
		Player1->Endturn();
		if (Player1->checkingHealth(Player1))
		{
			cout << Player1->GetPlayerName() << " has died \n";
			break;
		}
		cout << endl;
		cout << Player2->GetPlayerName() << " draws ";
		Player2->Draw(wizardDeck, Player1);
		Player2->Rest();
		Player2->depoly(Player2 ,Player1,combatContorller); /// place cards on table.
		Player2->attack(Player2, Player1, combatContorller); /// call the  combat control.
		
		Player2->Endturn();
		if (Player2->checkingHealth(Player2))
		{
			cout << Player1->GetPlayerName() << " has died \n";
			break;
		}
		mCurrentRound++;
		cout << endl;
		cout << endl;
	}
	GameManager->gameShutdown(GameManager);
}
