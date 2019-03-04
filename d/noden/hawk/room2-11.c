
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("中央大道");
        set("light",1);
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你继续走在内城的道路上，观察鸟人们所建筑的房子，发现大部份比较雄
伟的屋子都是颇新的，而老旧的房子则都是破破烂烂的，但是还是很多人住，
而较新较好的房子反而空空荡荡，或许是鸟人天性喜欢住在比较简陋的房子吧
....但不知道为什麽会多出这些新建筑呢？在所有的房子当中，你注意到一间
特别漂亮的房子，想要进去(enter) 看看吗？
LONG_DESCRIPTION
        );
        set( "exits", ([
        "northwest" : HAWK"room2-8",
        "south" : HAWK"room2-13",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_enter","enter");
}

int to_enter(string str)
{
        if (str == "house" || str == "building")
        {
                this_player()->move_player(HAWK"traroom","SNEAK");
                return 1;
        }
        else
        {
                tell_object(this_player(),"你想进去哪里??\n");
                return 1;
        }
        return 1;
}
