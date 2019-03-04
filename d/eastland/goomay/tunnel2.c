#include "goomay.h"

inherit ROOM;
int blocked;
void create()
{
        ::create() ;
	blocked=1;
        set_short( "地道" );
        set_long(
@LONG
这是一条窄窄的地道，你缩著身子只可以勉强的爬行前进，现在你
似乎已经到达这条地道的尽头了，因为前面被大量的泥沙石头掩埋了。
LONG
        );
	set("dig",1);
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
    if( arg=="forward" && !blocked)
	{
	if (blocked)
	{
	write(
		   "前面被堵住了，无法继续前进。\n");
		return 1;
	}
	if (random(5)==3 )
		{
        write(
          "你努力的向前爬，终於看到一线天光，你赶快往亮处爬了出去 !!\n");
      this_player()->move_player( Goomay"house_brush", "SNEAK" );
        tell_room( Goomay"house_brush", 
         this_player()->query("c_name") + "在一阵灰尘之中从地底钻了出来。\n"
        ,this_player() );

			return 1;
		}
	else
		{
        write( can_read_chinese() ?
          "你努力的向前爬，只见前面还是黑黝黝的一片，不知道还有多深。\n":
          "You climb forward but just see the darkness before you ! \n" );
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
void to_find_dig(string arg)
{
        object obj;

        if( !arg || (arg!="tunnel" && arg!="here" )) {
          write("这里没有你要挖的 ! \n");
          return;
	}
	if (!blocked)
	{
        write(
                   "地道已经打通了，你又继续挖，想把地道挖宽一点。\n");
		return ;
	}
	if (random(6)==3 )
                {
        write( 
          "你用铲子努力的清除堵住的砂石，累的满身大汗，最後突然「轰隆」一声，露出一个缺口 !!\n");
		blocked=0;
        set_long(
"这是一条窄窄的地道，你缩著身子只可以勉强的爬行前进，本来\n"+
"被堵住的部份现在似乎已经被打通，因为你感觉前面有清凉的微风吹\n"+
"来。\n");

                        return ;
}
        else
                {
	if (random(8)==2) {
        write(
          "你用铲子努力的清除堵住的砂石，突然用力过猛，「拍」的一声，铲子断了 !!。\n");
        if (obj = present ("shovel",this_player()))
          obj->remove();

                        return ;
	}
        write(
          "你用铲子努力的清除堵住的砂石，累的满身大汗，还是没能打通。\n");
                        return ;
		}
}

void reset()
{
    ::reset();
    set( "blocked",1);
    blocked = 1;
}
