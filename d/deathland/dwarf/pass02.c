
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("storage room","储藏室");
  set_long(@Long
一间很大的储藏室,里面放著一堆杂七杂八的东西.有一个很长的梯子(ladder)通向上面
,而北边有一间阴暗的地下室
Long
);

set("c_item_desc",([
    "ladder":"一道很长的梯子.\n",
   ]) );
set("exits",([
     "northdown":Deathland"/dwarf/pass01.c",
     ]) );
 ::reset();
}

void init()
{
 add_action("to_climb","climb");
}

int to_climb(string str)
{
  if(!str||str!="ladder") return 0;
  else {
    write("你爬上这梯子,花了许\久的时间才爬完这个非常长的梯子\n");
    say(this_player()->query("c_name")+"爬上了梯子\n");
    this_player()->move_player(Deathland"/palace/pa_0b","SNEAK","");
    return 1;
  } 
}
