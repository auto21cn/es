#include "ruin.h"
inherit ROOM;
inherit DOORS;

void create()
{
	::create();
  set("light",0);
  set_short("深山小径");
  set_long(@CLong
小径由东南往西蜿蜒而行, 幽暗的树林一路上始终掩盖著头上的阳光, 
使得这里格外的神秘。不过附近似乎有块平台 (plate), 你想或许可以过去
眺望一下附近的地形, 顺便享受一下久违的阳光。
CLong
);
set("exits",([
              "west"		: RUIN"first",
              "southeast"	: RUIN"first",
             ]));

set("item_desc",([
			"plate"	:@C_DESC_1
从这边看过去那块平台似乎不大, 不过进去那里看看应该有助於弄清
自己现在的所在地。
C_DESC_1
			]) );			
                          
  ::reset();
}

void init()
{
	add_action("enter_plate", "enter");
}

int enter_plate(string s)
{
	if (!s || strcmp(s,"plate")) {
		return notify_fail ( "你想去哪里?\n" );
	}	
	this_player()->move_player( RUIN"plate", 
	({  "%s走了过来。\n","%s向那块平台走去。\n"}) );
	return 1;
}
