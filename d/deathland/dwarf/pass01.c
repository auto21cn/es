
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("house of truffle","木菰种植室");
  set_long(@Long
Long
,@CLong
这里到处都是一排排的木架,而上面种满了木菰(truffle),一种美味的食物.矮人们花了
\许\久才发现了种植的方法,就是把它种在阴暗潮□的地底.由此可见这里离开地表的深度.
CLong
);

set("c_item_desc",([
    "truffle":"木菰,一种美味的食物.\n",
   ]) );
set("exits",([
     "southup":Deathland"/dwarf/pass02.c",
     ]) );
 ::reset();
#include <../replace_room.h>
}

