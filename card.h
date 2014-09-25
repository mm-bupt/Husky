/*
 * =====================================================================================
 *        Class:  Card
 *  Description:  
 * =====================================================================================
 */
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
		CARDTYPE_E	cardtype;
		int         reference;
		int			cardid;
}; /* -----  end of class Card  ----- */

