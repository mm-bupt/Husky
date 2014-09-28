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
	GAMESTATE_WAITACTION,	
	GAMESTATE_WAITPAI,
	GAMESTATE_OVER
}GAMESTATE_E;

class Game
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Game (void);                             /* constructor */
		Game (PLAYERNUM_E ePlayernum);                             /* constructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */
		int init();
		
		void schedule(Message *message);
		void schedule(void);
		void adduser(Player *player);
		
		void dispatchCard(std::vector<int> &vector);
	protected:
		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  DATA MEMBERS  ======================================= */
		std::vector<Deck *> decklist;
		std::vector<Player *> playerlist;
		std::vector<Action *> actionlist;
		PLAYERNUM_E ePlayerNum;
		int nextuserid;
		GAMESTATE_E eGameState;
		void start();
}; /* -----  end of class Game  ----- */

