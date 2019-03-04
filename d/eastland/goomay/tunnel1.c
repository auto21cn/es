#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_short("地道" );
        set_long(
@LONG
这是一条窄窄的地道，你缩著身子只可以勉强的爬行前进，这条
地道不知道有多长，也不知道另一端是通往哪里。
LONG
        );
        
        reset();
}

void init()
{
    add_action("to_climb", "climb");
}
int to_climb( string arg )
{
    if( !arg || (arg != "backward" && arg !="forward") )
      return notify_fail("Climb backward or forward ?\n");
    if( arg=="forward" )
	{
	if (random(6)==3 )
		{
        write(
          "你努力的向前爬，终於到了洞口的一端，但是出口已经被一大堆泥土封住了 !!\n");
      this_player()->move_player( Goomay"tunnel2", "SNEAK" );
        tell_room( Goomay"tunnel2", 
         this_player()->query("c_name") + "在一阵灰尘之中从地道那端爬出来。\n"
        ,this_player() );

			return 1;
		}
	else
		{
        write(
          "你努力的向前爬，只见前面还是黑黝黝的一片，不知道还有多深。\n");
			return 1;
		}
	}
        write( 
          "你决定退出地道，一路倒著爬出地道。\n");
      this_player()->move_player( Goomay"jail_room2", "SNEAK" );
        tell_room( Goomay"jail_room2", 
         this_player()->query("c_name") + "在一阵灰尘之中从地洞中钻了出来。\n"
        ,this_player() );

    return 1;
}
