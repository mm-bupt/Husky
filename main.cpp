#include <stdio.h>
#include <iostream> 
#include <vector>
#include "define.h"
#include "director.h"
#include "card.h"
#include "deck.h"
#include "player.h"
#include "message.h"
#include "game.h"

using namespace std;

int main (int argc, char *argv[])
{
	Game *game = new Game();
	Player *a = new Player(1);
	Player *b = new Player(2);
	Player *c = new Player(3);
	Player *d = new Player(4);

	a->setLocate(0);
	b->setLocate(1);
	c->setLocate(2);
	d->setLocate(3);
	
	if (ERROR_SUCCESS != game->init())
	{
		delete(game);
	}

	game->adduser(a);
	game->adduser(b);
	game->adduser(c);
	game->adduser(d);

	cout << "after\r\n";

	game->schedule();
	msg->setMessageType(MSGTYPE_DEBUG);
	game->schedule(msg);	
	return 0;
}
