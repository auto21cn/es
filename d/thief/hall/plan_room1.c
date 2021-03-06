#include <mudlib.h>

inherit "/d/thief/hall/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("诡计研究中心");
	set_long( @LONG_DESCRIPTION
这里是小偷们互相交换诡计和骗术的地方，不少小偷都以能够将自己的点子
留在这里为荣，你在这里可以学习(study)其他小偷所留下来的聪明点子，在你
的前方桌上有一本巨大的书，你可以先从书上的目录(catalog)找起。
PS. 目前尚未开放学习。
LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"catalog": "view_catalog" ]) );
	set( "exits", ([ 
		"north" : "/d/thief/hall/thief_guild" ]) );
	set_tricks( ([
		"set-fire"   	 : ({ "trick", 20, 4, 20, 100 }),
		"shut-up"		 : ({ "trick", 35, 3, 10, 150 }),
		"bag-bag"    	 : ({ "trick", 60, 4, 10, 200 }),
		"not-me" 	     : ({ "trick", 15, 4, 10, 100 }),
		"throw-dagger"   : ({ "trick", 15, 6,  5, 100 })
	]) );
	
	reset();
}

