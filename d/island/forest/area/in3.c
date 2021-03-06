#include "../tsunami.h"
#include "anthill.c"

inherit ROOM;
void create()
{
    ::create();
    set_short("瀑布顶端");
    set_long(@LONG
这儿再往东走一些，就是最高点了；原来瀑布顶端的那一头是一个大悬崖。
LONG
            );
    set_outside("island");
    set("exits",([
        "east":AREA"h2"]) ); 
    reset();
}

void init()
{
    add_action("do_search","search");
    add_action("do_climb","climb");
}

int do_search()
{
      tell_object(this_player(),
      "嗯～～！根据你推断的结果，确信这里有攀爬(climb)过的痕迹.......\n");
      return 1;
}

int do_climb( string arg)
{
    if( !arg || arg=="" )
      return notify_fail("你要爬哪个方向呢？\n");
    if( arg != "down" )
      return notify_fail("这里就是瀑布的顶端了，你要往哪儿爬呢？\n");
    if( arg == "down" )
      to_climb_down( this_player(), AREA"in2", AREA"in", 35, 15);
    return 1;
}
