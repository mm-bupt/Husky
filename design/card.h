/*
 * =====================================================================================
 *        Class:  Card
 *  Description:  
 * =====================================================================================
 */

#define CARD_STATUES_SHOW     1 << 0
#define CARD_STATUES_DOWN     1 << 1

class Card
{
	public:
		Card (CARDTYPE_E cardtype, int cardid);                       /* constructor */

		CARDTYPE_E getcardtype(void);
		int getcardid(void);

		int increaseReference();
		int decreaseReference();
	protected:

	private:
		CARDTYPE_E		eCardType;
		unsigned char	ucCardStatues;
		int				reference;
		int				cardid;
}; /* -----  end of class Card  ----- */

