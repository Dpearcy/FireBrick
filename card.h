#pragma once
#include "file needed.h"
const int eplion = 0; //// This sets the number Zero  used to set values to zero. 
class CCard ////This is used to hold the cards for the deck.
{
private:
	 struct SCard //// This holds the data for a card got from the file. 
{
	int mtype; //// This holds the card type for the card.
	char mName[15];//// This holds the name of the card given.
	int mAttack;//// This holds number of the attack given for the card.
	int mHealth;  //// This holds the number of the health givenfor the card.
	bool mDefended  = false; //// This holds if the card has  something  equiped.
};
	SCard* pCard;//// This holds the card for the  deck used later.
	int mNameCounter = eplion; //// This is the number goes thougth the arrary in  the name.  
public:
	CCard();//// This creates the instance for the card  used to store the card data from the file. 
	~CCard();//// This deletes the  instance  when the class is  destoryed.
	virtual int FindCardtype(); //// This returns the  card type number  stored the card.
	void setCardType(int value);//// This sets the card type this function is called when the file is loaded
								//// and gets type of the card in the file.
	void setCardName(char value);//// This sets the card name this function is called when the file is loaded
								 //// and  gets the name given  by the card in the file. 
	void setCardAttack(int value);//// This sets the card type this function is called when the file is loaded
								  //// and gets the attack value of the card in the file.
	void setCardHealth(int value);//// This sets the card type this function is called when the file is loaded
								  //// and gets the health from the card value.
	void setBoolDefended(bool yes); //// This sets the  defended value used for  checking if card has proection.
		int getCardType();////  This gets the card type from the card instance and returns it to be displayed on screen later.
		std::string getCardName();//// This displays the name  of the card on srceen as the card name is stored  as  a char array.
		int getCardAttack();//// This gets the attack value from the card instance and returns it  to  be display on srceen later.
		int getCardHealth(); //// This gets the health value from the card instance and returns it to be display on srceen later.
		void outPutCardName();//// This goes  though the char arrary  and outputs the name. 
};
