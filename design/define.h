typedef enum en_cardtype
{	
	t1,	t2,	t3,	t4,	t5,	t6,	t7,	t8,	t9,	
	w1,	w2,	w3,	w4,	w5,	w6,	w7,	w8,	w9, 
	b1,	b2,	b3,	b4,	b5,	b6,	b7,	b8,	b9,	
	east,	south,	west,	north,
	zhong,	fa,		bai,
	butt
}CARDTYPE_E;

typedef enum en_numofplayer
{
	PLAYERNUM_NOBODY = 0,
	PLAYERNUM_NORMAL = 4
}PLAYERNUM_E;

typedef enum en_decktype
{
	DECKTYPE_ALL = 0,
	DECKTYPE_EMPTY,
}DECKTYPE_E;

typedef enum en_error
{
	ERROR_SUCCESS = 0,
	ERROR_FAILED,
	ERROR_ALLOC,
	ERROR_NOFIND
}ERROR_E;

