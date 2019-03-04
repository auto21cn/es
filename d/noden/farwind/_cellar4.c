// File: /open/polo/noden/farwind/cellar4.c
// Generated by Roommaker Mon Nov  6 06:28:28 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地洞");
	ob->set_long( @LONG_DESCRIPTION
你现在站在一个阴暗的地洞中，地洞中央有一个小小的水池(pool)，一些
食物的残渣、碎屑散落在水池周围。这些残渣散发出一股腐败发霉的味道，使
你不由自主地掩住鼻子。西北边有一条通道。
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"northwest" : "/d/noden/farwind/cellar3.c", 
		"east" : "/d/noden/farwind/cellar5.c", 
		"south" : "/d/noden/farwind/tunnel1.c" ]) );
	ob->set( "item_desc", ([ 
		"pool" : @LONG_TEXT
与其说这是个水池，不如说它是个水洼。水面上飘著一些吃剩的食物
残渣，你发现水里面好像有一些东西在游动，不过水实在太脏了，你
无法确定是什麽东西。
LONG_TEXT
 ]) );
	ob->set( "objects", ([ 
		"grey rat" : "/d/noden/farwind/monster/grey_rat", 
		"fat rat" : "/d/noden/farwind/monster/fat_rat" ]) );
	ob->reset();
}
