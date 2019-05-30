#pragma once
#include "card.h"
#include "file needed.h"
using namespace std;
class CFile //// This class is used to load all the files needed for the game.
{
private:
	ifstream  mInFileSorceress;//// This is a place holder so the file can be loaded.
	ifstream mInFileWizard;//// This is a place holder so the file can be loaded.
	string mFileInput;//// This is used to read the file given.
	int mEndOfType = eplion;//// This is used  to work out where the space is between the type and the name
	const enum ECard//// These are where the  parts of the file can go.
	{
		type, name, attack, health
	};
	deque <unique_ptr <CCard > > pSorceressCards; //// This stores the cards given from the sorceress file. 
	deque <unique_ptr <CCard > > pWizardCards;//// This stores the cards given from the wizard file.
	unique_ptr<CCard>  pTmp;
	int mEndofattack;//// This is used  to work out where the space is between the name and the attack value
	 int mEndOfName;//// This is used  to work out where the space is between the start of name and the end of the name. 
	 ECard EElementsOfACard;///// This is used to  place  parts of the file  in the right parts of the card class.
	 int mStartOfTmp = 0; //// This is to start the tmp card used to read the file.
public:
	CFile();//// This creates an stance of the deck that holds the card given by the file.
	~CFile();//// This deletes an stance of the deck that holds the card given by the file.
	void settingUpCards(ECard& elementsOfACard, int currantelement, int& endOfType, int& endnofname,
		std::string& fileInput, deque < unique_ptr <CCard>>& sorceressCards);//// This places each element  form  a line  in the file  in the right part. 
	int CombineNumber(int a, int b);//// This comnines the number for the type given  for each card  (I did not write this function I it got from stackoverflow. ref https://stackoverflow.com/questions/2611081/combine-two-numbers-into-one-example-123-and-456-become-123456).  
	void loadFiles();//// This loads the files needed and calls the  placement function .
	deque <unique_ptr <CCard >> GetSorceressDeck();//// the return the temp sorcerss deck used to store the card from the file and places it in the managers deck.
	deque <unique_ptr <CCard >> GetWizardDeck();//// the return the temp wizard deck used to store the card from the file and places it in the managers deck.
};
