
#include"stdafx.h"
#include"card.h"
CCard::CCard()
{
	pCard = new SCard;
}
CCard::~CCard()
{
	delete(pCard);
}
int CCard::FindCardtype()
{
	return (pCard->mtype);
}
 void CCard::setCardType(int value)
 {
	 pCard->mtype = value;
 }
 
 void CCard::setCardName(char value)
 {
	 pCard->mName[mNameCounter] = value;
 }
 void CCard::setCardAttack(int value)
 {
	 pCard->mAttack = value;
	 mNameCounter = eplion;
 }
 void CCard::setCardHealth(int value)
 {
	 if (pCard->mDefended)
	 {
		pCard->mHealth = value + 1;
	 }
	 else pCard->mHealth = value;
 }
 void CCard::setBoolDefended(bool yes)
 {
	 pCard->mDefended = yes;
 }
#ifdef _DEBUG 
 int  CCard::getCardType()
 {	 
	 return pCard->mtype; 
 }
 std::string CCard::getCardName()
 {	
	 
		mNameCounter++;
		return  pCard->mName;
 }
 int CCard::getCardAttack()
 { 
	 return pCard->mAttack; 
 }
 int CCard::getCardHealth()
 {	
	 return pCard->mHealth; 
 }
 void CCard::outPutCardName()
 {
	 int numberOfChars = eplion; //// This goes  though the char arrary  and outputs the name. 
	 while (pCard->mName[numberOfChars] != 'Í')
	 {
		std::cout << pCard->mName[numberOfChars];
		numberOfChars++;
	 }
 }
#endif // _DEBUG