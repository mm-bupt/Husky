/*
 * =====================================================================================
 *        Class:  Message
 *  Description:  
 * =====================================================================================
 */

typedef enum en_MessageType
{
	MSGTYPE_USER_CHI,
	MSGTYPE_USER_READY,
	MSGTYPE_USER_PENG,
	MSGTYPE_USER_HU,
	MSGTYPE_USER_GIVEUP,
	MSGTYPE_USER_PUT,
	MSGTYPE_USER_INIT,
	MSGTYPE_USER_OPTION,
	MSGTYPE_SERVERMSG,
	MSGTYPE_DEBUG,
	MSGTYPE_BUTT
}MESSAGETYPE_E;

class Message
{
	public:
		Message ();                             /* constructor */

	protected:

	private:
		int remote;
	    	
}; /* -----  end of class Message  ----- */

