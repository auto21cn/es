#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("树林");
	set_long( @LONG
你置身在一片里，树枝遮住了射照下来的光线，显得有点阴凉。这树林里不时
有鸟类啾鸣的声音，另外还有些动物隐藏其中。在你北边还有间小小的茅屋(house
)，那茅屋不怎麽起眼，你可以进去看看(enter)，南边则是东郊。
LONG
	);
	set( "exits", ([ 
            "south" : SCITY"plain1",
        ]) );
	reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
      return notify_fail("你要进入那里?\n");
      this_player()->move_player(SCITY"house3",({
                     "%s进入了一间小茅屋。\n",
                     "%s从外面走了进来.\n"}),"");
      return 1;
}