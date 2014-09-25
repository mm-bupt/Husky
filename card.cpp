#include "define.h"
#include "card.h"

Card::Card(CARDTYPE_E cardtype, int cardid)
{
	this->cardtype = cardtype;
	this->cardid = cardid;
	this->reference = 0;	
	return;
}

int Card::getcardid()
{
	return this->cardid;
}

CARDTYPE_E Card::getcardtype(void)
{
	return this->cardtype;
}

int Card::increaseReference()
{
	this->reference += 1;
	return this->reference;
}

int Card::decreaseReference()
{
	this->reference -= 1;
	return this->reference;
}
