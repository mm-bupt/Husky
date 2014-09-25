#include <stdio.h>
#include <vector>
#include "define.h"
#include "card.h"
#include "deck.h"
#include "player.h"
#include "message.h"
#include "game.h"

using namespace std;

Game::Game (void)
{
	this->ePlayerNum = PLAYERNUM_NORMAL;
	return;
}

Game::Game (PLAYERNUM_E ePlayerNum)
{
	this->ePlayerNum = ePlayerNum;
	return;
}

int Game::init()
{
	int i;
	Deck *deck;
	Deck *deck2;
	Deck *deckuser;

	deck = new Deck();
	if (NULL == deck)
	{
		return ERROR_ALLOC;
	}

	deck->GetDeckAllCard();

	this->decklist.push_back(deck);
	deck2 = new Deck();
	if (NULL == deck2)
	{
		return ERROR_ALLOC;
	}

	*deck2 = *deck;
	this->decklist.push_back(deck2);

	for (i = 0; i< ePlayerNum * 2 + 1; i++)
	{
		deckuser = new Deck();
		if (NULL == deckuser)
		{
			return ERROR_ALLOC;
		}
	    this->decklist.push_back(deckuser);
	}

	this->eGameState = GAMESTATE_INIT;
	return ERROR_SUCCESS;
}

void Game::schedule(void)
{
	Message *msg;
	switch(this->eGameState)
	{
		case GAMESTATE_INIT:
		{
			vector<int> split;
			split.push_back(4);
			split.push_back(4);
			split.push_back(4);
			split.push_back(1);
			this->dispatchCard(split);
			this->eGameState = GAMESTATE_START;
			break;
		}
		case GAMESTATE_START:
		{
			this->start();
			break;
		}
		case GAMESTATE_OVER:
		{
			break;
		}
		default:
		{
			break;
		}
	}
	
	return;
}

void Game::schedule(Message *msg)
{
	switch(msg->getMessageType())
	{
		case MSGTYPE_USER_CHI :
		case MSGTYPE_USER_GIVEUP :
		case MSGTYPE_USER_PENG :	
		{
			if (this->eGameState != GAMESTATE_WAITACTION)	
			{
				break;
			}
			if (msg->getPlayer()->getID() != (*this->playerlist.begin())->getID())
			{
				break;
			}
		}
		case MSGTYPE_USER_READY :
		{
			if (GAMESTATE_START == this->eGameState && 
				(*this->playerlist.begin())->getID() == msg->getPlayer()->getID())
			{
				int deckid = 2 + msg->getPlayer()->getLocate();
				Deck *deck = this->decklist.at(1);
				Deck *deckuser = this->decklist.at(deckid);

				Card *card = deck.Pop();
				deckuser->Push(card);
			}
			break;
		}
		case MSGTYPE_DEBUG :
		{
			vector <Deck *> ::iterator iterdeck;
			for (iterdeck = this->decklist.begin();	iterdeck != this->decklist.end(); iterdeck++)
			{
				(*iterdeck)->show();
			}
			break;
		}
		default :
		{
			break;
		}
	}	

	return;
}

Message *Game::popMessage(void)
{
	return *(this->msglist.begin());
}

void Game::dispatchCard(std::vector<int> &vector)
{
	int i, j;
	Deck *deck;
	Deck *deckuser;

	std::vector <int> ::iterator iter; 

	deck = *(this->decklist.begin() + 1);
	
	for (iter = vector.begin(); iter != vector.end(); iter++)
	{
		for (i = 0; i < 4; i++)
		{
			deckuser = *(this->decklist.begin() + 2 + (*(this->playerlist.begin() + i))->getLocate());
			for (j = 0; j < *iter; j++)
			{
				deckuser->Push(deck->Pop());
			}
		}
	}

	this->nextuserid = 0;
	return;
}

void Game::adduser(Player *player)
{
	this->playerlist.push_back(player);
	return;
}

void Game::start()
{
	int path;
	int deckid = 2 + this->playerlist.at(this->nextuserid)->getLocate();

	Deck *deck = this->decklist.at(1);
	Deck *deckuser = this->decklist.at(deckid);

	deckuser->Push(deck->Pop());

	this->eGameState = GAMESTATE_WAITACTION;

	return;
}
