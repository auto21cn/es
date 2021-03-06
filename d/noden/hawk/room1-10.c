
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("外城小径");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
自从几年前一场大战之後，鸟人族就退守到天空之城，而为了避免敌
人再度入侵，鸟人们做了许多防范的工事，将天空之城外又加盖了一小城
，也就是现在你所在的外城。
    在外城居住的有两种人，一种是负责守卫天空之城的士兵们，另外就
是一些比较穷和年老无依的鸟人们，他们就住在外城的贫民窟里。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "east" : HAWK"room1-9",
        "south" : HAWK"room1-11",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="east" || str=="south" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}
