/*
 * =====================================================================================
 *        Class:  Deck
 *  Description:  
 * =====================================================================================
 */
class Deck
{
	public:
		Deck (void);		                          /* constructor */
		~Deck (void);		                          /* disconstructor */

		int     Init(DECKTYPE_E eDeckType);
		int		Insert(Card *card);
		Card *	GetAndDeleteFirst(void);
		Card *	GetAndDeleteByCardType(CARDTYPE_E eCardType);
		Card *  GetAndDeleteCardId(int cardid);

		Deck&	operator=(Deck &deck);

		/* debug */
		void    show (void);
	protected:

	private:
		void	Mix (void);

		std::vector<Card *> vCCard;
}; /* -----  end of class Deck  ----- */

