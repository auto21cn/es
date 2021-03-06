//#pragma save_binary

#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "杂项魔法图书室");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这里所收藏的魔法书多半是在整理银色之塔遗迹时，从一些破旧的石棺或箱子
中发现的，虽然它们多半残缺不全，但是经过几位著名魔法师的整理之後，也已经
初具规模，这里平常较少有魔法师进来，所以到处积满灰尘，你可以查阅前面书柜
上的清单(list)，看看这里有哪些法术的资料。往南通过一条长长的走道可以回到
图书馆大厅。
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"south" : MAGE"library" ]) );
	set( "item_func", ([
		"list" : "view_catalog" ]) );
	set_spells( ([
	   "wizard-eye"     : ({ "misc", 10, 3, 15, 150 }),
	   "magical-shield" : ({ "misc", 40, 2, 15, 200 }),
	   "detect-invis" : ({ "misc", 10, 6, 10, 250 }),
	   "detect-hide" : ({ "misc", 10, 6, 10, 250 }),
	   "magic-cube"     : ({ "misc", 20, 2, 20, 200 }),
	]) );
	reset();
}
