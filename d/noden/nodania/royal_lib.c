#include "nodania.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	seteuid(getuid());
	set( "light", 1 );
	set_short( "国王的图书室" );
	set_long(@CLONG
你来到了国王耶拉曼十一世的专用图书室，这里的藏书虽然不及诺
达尼亚大图书馆丰富，但也是应有尽有。你可以从国王书柜中的书籍种
类发现耶拉曼十一世对有关植物的书特别有兴趣。
CLONG
	);
	set( "exits", ([
		"west" : NODANIA"e_throne"
	]) );
	create_door( "west", "east", ([
		"keyword" : ({ "oak door", "door" }),
		"name" : "oak door",
		"c_name" : "橡木门",
		"c_desc" : "一雕饰华丽的橡木门。\n",
		"status" : "locked",
		"lock" : "KING_YARAMON_XI_LIBRARY"
	]) );
/*
	set( "objects", ([
		"Annihilator": "/adm/gods/annihilator" ,
		"Kyoko": "/adm/gods/kyoko",
		"Layuter": "/adm/gods/layuter",
		"Echobomber": "adm/gods/echobomber", ]) );
*/
	reset();
}

void clean_up() { return 0; }
