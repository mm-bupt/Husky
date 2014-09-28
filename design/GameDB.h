/*
 * =====================================================================================
 *		COPYRIGHT:  Copyright(C) 2007-2015 Neusoft
 *       FILENAME:  GameDB.h
 *        VERSION:  1.0
 *         AUTHOR:  maming (), ma.ming@neusoft.com
 *			 DATE:  09/28/2014 04:57:04 PM
 *    DESCRIPTION:  
 * -------------------------------------------------------------------------------------
 * CHANGE HISTORY:
 * DATE				REV		WHO			DESCRIPTION
 *
 * =====================================================================================
 */


/*
 * =====================================================================================
 *        Class:  GameDB
 *  Description:  
 * =====================================================================================
 */
class GameDB
{
	public:
		GameDB ();                             /* constructor */
		Game *GetGameByPlayID(int iPlayerID);
		Game *GetGameByTag(int iTag);
		Game *CreateNewGame(int iTag);
		void Destory(Game *);
		void DestoryByTag(int iTag);

	protected:

	private:
		vector <Game *> vCGame;
}; /* -----  end of class GameDB  ----- */

