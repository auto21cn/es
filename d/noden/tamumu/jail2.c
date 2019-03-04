// File: /d/noden/tamumu/jail2.c
// Generated by Roommaker Wed Dec 15 07:48:08 1993

#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("监牢");
	set_long( @C_LONG_DESCRIPTION
这里是一间狭小的监牢，在你的头顶正上方有一个洞穴，但是你够不著，地
上铺著一些稻草或是某种晒乾的植物，一些白骨(bones)和破碎的衣服(clothes)
散布在四周，这个地方看起来很久没有「人类」住过了，虽然好像有某种怪物居
住在这里....。
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([ 
		"clothes" : @LONG_TEXT
这些衣服碎片上面满是血迹，它原来的主人一定是遭到了不幸——被某种怪物
活活撕裂了....。
LONG_TEXT
, 
		"bones" : "这些白骨看起来年代已经非常久远，上面还有著不少齿痕。\n" ]) );
	set( "exits", ([ 
		"south" : "/d/noden/tamumu/cave8" ]) );
	create_door( "south", "north", ([
		"keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "铁门",
		"c_desc" : "一扇厚实的铁门，上面有一道凹槽",
		"status" : "locked",
		"lock" : "TAMUMU_JAIL1"
	]) );
	set( "objects", ([
		"flesheater": "/d/noden/tamumu/monster/flesheater" ]) );
	reset();
}

void init()
{
   if( this_player() ) this_player()->set_explore("noden#14");
}
