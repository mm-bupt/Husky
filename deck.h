/*
 * =====================================================================================
 *        Class:  Deck
 *  Description:  
 * =====================================================================================
 */
class Deck
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Deck (void);		                          /* constructor */
		~Deck (void);		                          /* disconstructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */
		void	Mix (void);
		int		Push (Card *card);
		Card *	Pop (void);
		Card *	Pop (CARDTYPE_E cardtype);
		int		Delete (int cardid);
		Card *	Get (int cardseq);
		int     GetDeckAllCard(void);
		Deck&	operator=(Deck &deck);
		void    show (void);
	protected:
		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  DATA MEMBERS  ======================================= */
		std::vector<Card *> cardptrlist;
}; /* -----  end of class Deck  ----- */

