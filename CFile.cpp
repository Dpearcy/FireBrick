#include "stdafx.h"
#include "file needed.h"
#include "CFlie.h"
using namespace std;
CFile::CFile()
{
	//// file stuff  goes  here 
	mInFileSorceress.open("sorceress.txt");
	if (!mInFileSorceress)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
	mInFileWizard.open("wizard.txt");
	if (!mInFileWizard)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
	pTmp.reset ( new CCard);
}
CFile::~CFile()
{
	mInFileSorceress.close();
	mInFileWizard.close();
	mFileInput.clear();
	///delete this  what ever  is made in the class. 
}
void CFile::loadFiles()
{
	while (mInFileSorceress.good())
	{
		getline(mInFileSorceress, mFileInput);
		for (int currantElement = eplion; currantElement != 4; currantElement++)
		{
			settingUpCards(EElementsOfACard, currantElement, mEndOfType, mEndOfName, mFileInput, pSorceressCards);//
		}
	}
	mStartOfTmp = eplion;
	mEndOfType = eplion;
	mEndofattack = eplion;
	mEndOfName = eplion;
	while (mInFileWizard.good())
	{
		getline(mInFileWizard, mFileInput);
		for (int currantelement = eplion; currantelement != 4; currantelement++)
		{
			settingUpCards(EElementsOfACard, currantelement, mEndOfType, mEndOfName, mFileInput, pWizardCards);
		}
	}
	//std::cout << std::endl;
}
int CFile::CombineNumber(int a, int b)
{//// got from stack overthorw   not my code 
	int times = 1;
	times *= 10;
	return a*times + b;
}
void CFile::settingUpCards(ECard& elementsOfACard, int currantelement, int& endOfType, int& endnofname,
	std::string& fileInput, deque < unique_ptr <CCard>>& sorceressCards)
{
	switch (currantelement)
	{

	case(type):

		if (fileInput[1] == ' ')
		{
			pTmp->setCardType(fileInput[eplion] - 48);
			//std::cout << Tmp->getCardType() << "  ";
			endOfType = 1;
		}
		else if (fileInput[2] == ' ')
		{
			pTmp->setCardType(CombineNumber(
				fileInput[eplion] - 48, fileInput[1] - 48));
			//std::cout << Tmp->getCardType() << "  ";
			endOfType = 2;
		}
		

		break;
	case (name):
		if (endOfType == 1)
		{

			for (int i = 2; fileInput[i] != ' '; i++)
			{
				pTmp->setCardName(fileInput[i]);
				pTmp->getCardName();
				endnofname = i;
			}
		}
		else if (endOfType == 2)
		{
			for (int i = 3; fileInput[i] != ' '; i++)
			{
				pTmp->setCardName(fileInput[i]);
				 pTmp->getCardName();
				
				endnofname = i;
			}
		}
		break;
	case(attack):
		for (int i = endnofname + 2; fileInput[i] != ' '; i++)
		{
			if (fileInput[i] == '\0')
			{
				break;
			}
			pTmp->setCardAttack(fileInput[i] - 48);
			//std::cout << " " << Tmp->getCardAttack() << " ";
			mEndofattack = i;
		}
		break;
	case(health):
		for (int i = mEndofattack + 1; fileInput[i] != '\0'; i++)
		{
			pTmp->setCardHealth(fileInput[i] - 48);

		}
		//std::cout << Tmp->getCardHealth();
		//std::cout << std::endl;
		
		sorceressCards.push_back(move(pTmp));
		 pTmp.reset(new CCard);
		 break;
	}
	
}
deque <unique_ptr < CCard> > CFile::GetSorceressDeck()
{
	return move(pSorceressCards);
	
}
deque <unique_ptr < CCard> > CFile::GetWizardDeck()
{
	return move(pWizardCards);
}