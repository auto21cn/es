//#pragma save_binary

// translation done. -Elon 03-10-94 left out minor details.
#include "../moyada.h"
#include <money.h>

inherit SHOP;
inherit DOORS;

void create()
{
	::create() ;
	set("light", 1);
	set_short( "商店" );
	set_long( @C_LONG
欢迎来到摩亚达镇最大也是唯一的商店，这家商店的老板王虎是远
从中国西安市来这里发展，由於原本是个御膳师，所以他煮的菜可说是
远近驰名。这家商店新开不久，桌椅全是新的，四处整理得一尘不染。
墙上点燃著数把火炬，照亮整个屋子。
C_LONG
);
	set( "exits", ([ 
	  "west" : MOYADA"mainrd1", 
	  "down" : MOYADA"shop/cellar",
	]) );
	
	storeroom()->set("storage", 2);
    storeroom()->set( "objects", ([
        "lamp" : "/obj/lamp",
        "bandage" : "/obj/bandage",
    ]) );
	set( "objects", ([
	    "trashcan" : "/obj/trashcan",
		"Wan Fu"  : MOYADA"monster/wanfu",
		"grey"    : MOYADA"monster/grey",
	]) );
    create_door( "west", "east", ([
	  "keyword" : ({ "wodden door", "door", }),
	  "name"    : "wodden door",
	  "c_name"  : "木门",
	  "c_desc"  : "房子出口的木门",
	  "status"  : "open",
	]) );
	reset();
	replace_program(SHOP);
}
