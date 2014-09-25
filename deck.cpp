#include <vector>
#include <iostream>
#include "define.h"
#include "card.h"
#include "deck.h"
#include <algorithm>

using namespace std;

Deck::Deck (void)
{	
	return;	
}

Deck::~Deck (void)
{
	Card *card;
	while(card = this->Pop())
	{
		delete(card);
	}

	return;
}

void Deck::Mix (void)
{
	if (!this->cardptrlist.empty())
	{
		random_shuffle(this->cardptrlist.begin(), this->cardptrlist.end());
	}
	
	return; 		
}

int Deck::Push (Card *card)
{
	card->increaseReference();
	this->cardptrlist.push_back(card);
	
	return this->cardptrlist.size();
}

Card * Deck::Pop(void)
{	
	Card * card;
	
	if (this->cardptrlist.empty())
	{
		return NULL;
	}

	card = *this->cardptrlist.begin();
	this->cardptrlist.erase(this->cardptrlist.begin());
	card->decreaseReference();
	return card;
}

Card * Deck::Pop(CARDTYPE_E cardtype)
{
	vector<Card *>::iterator iter;
	Card *card = NULL;

	if (this->cardptrlist.empty())
	{
		return NULL;
	}

	for (iter = this->cardptrlist.begin(); iter != this->cardptrlist.end(); iter++)
	{
		if (cardtype == (*iter)->getcardtype())
		{
			card = *iter;
			this->cardptrlist.erase(iter);
			card->decreaseReference();
			break;
		}
	}
		
	return card;
}


int	Deck::Delete (int cardid)
{
	vector<Card *>::iterator iter;
	Card *card = NULL;
	for (iter = this->cardptrlist.begin(); iter != this->cardptrlist.end(); iter++)
	{
		if (cardid == (*iter)->getcardid())
		{
			card = *iter;
			this->cardptrlist.erase(iter);
			delete(card);

			break;
		}
	}

	if (NULL == card)
	{
		return 0;                               /*  Card not found */
	}

	return 1;                                   /*  Card found and delete */
}

Card * Deck::Get (int cardseq)
{	
	Card *card = NULL;
	
	if (this->cardptrlist.size() >= cardseq)
	{
		card = *(this->cardptrlist.begin() + cardseq);
	}

	return card;
}

int Deck::GetDeckAllCard(void)
{
	CARDTYPE_E i;
	int count = 0,j;
	Card *card;
	
	for (i = tiao_1; i < butt; i = (CARDTYPE_E)((int)i + 1))
	{
		for (j = 0; j < 4; j++)
		{
			card = new Card(i, (int)i * 4 + j);
			if (NULL != card)
			{
				this->Push(card);
				count++;
			}
		}
	}
	
	if (count < butt * 4)
	{
		return 0;
	}	
	
	this->Mix();

	return 1;
}

Deck& Deck::operator=(Deck& deck) 
{
	vector<Card *>::iterator iter;
	
	for (iter = deck.cardptrlist.begin(); iter != deck.cardptrlist.end(); iter++)
	{
		this->Push(*iter);	
	}

	return *this;
}

void Deck::show (void)
{
	int count = 0;
	vector <Card *> ::iterator iter;
	
	if (this->cardptrlist.empty())
	{
		return;
	}

	for (iter =	this->cardptrlist.begin(); iter != this->cardptrlist.end(); iter++)
	{
		cout << (*iter)->getcardid() << "\t"; 
		count ++;
		if (count >= 5)
		{
			count = 0;
			cout <<"\r\n";
		}
	}
	cout << "\r\n\r\n\r\n";	
	return;
}
