
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("Troll Altar","巨人祭坛");
        set_long(@Long
Long
,@Clong
这里似乎是一个屠宰场,但是两旁却有许许多多奇奇怪怪的图腾矗立著,以
及一个很巨大的塑像立在你的面前,山顶巨人常常用活生生的人,去祭祀祈求战
争残杀的胜利.
Clong
	);
set("exits",([
   "east":Deathland"/troll/cave_06",
            ]) );
::reset();
#include <../replace_room.h>
}

void init()
{
  this_player()->set_explore( "deathland#2" );
}

