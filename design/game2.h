/*
 * =====================================================================================
 *        Class:  Game
 *  Description:   
 * =====================================================================================
 */

typedef enum en_gamestate
{
	GAMESTATE_NULL,
	GAMESTATE_INIT,
	GAMESTATE_START,
	GAMESTATE_WAITUSER,
	GAMESTATE_OVER
}GAMESTATE_E;

class Game
{
	public:
		Game (void);                             /* constructor */
		Game (PLAYERNUM_E ePlayernum);                             /* constructor */

		int init();
		
		void schedule(Action *message);
		void schedule(void);
		void adduser(Player *player);
		
		void dispatchCard(std::vector<int> &vector);
	protected:

	private:
		int epollfd;

		std::vector<Deck *> decklist;
		std::vector<Player *> playerlist;
		std::vector<Action *> actionlist;
		PLAYERNUM_E ePlayerNum;
		int nextuserid;
		GAMESTATE_E eGameState;
		void start();
}; /* -----  end of class Game  ----- */

