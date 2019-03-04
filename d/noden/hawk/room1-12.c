
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("通往军营的小路");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你可以看到许多军营 (military building)矗立在小路的两旁，往南是鸟
人族老人们和聚居的地方。似乎还有一栋高高的建筑物，不知道是啥东东。不
过你可能可以从旁边的楼梯爬上去看看。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "south" : HAWK"room1-13",
        "east" : HAWK"room1-11"
              ]) );
        set("c_item_desc",([
                "building":"这是一栋不怎麽显眼的军营，但是隐约可以听到练兵的吆喝声。\n",
                        ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_climb","climb");
}

int to_climb(string s)
{
        if ( (s != "ladder") && (s != "楼梯") ) return 0;
        tell_room(environment(this_player()),
                "你看到"+this_player()->query("c_name")+
                "像乌龟一样沿著楼梯慢慢往上爬!\n",this_player());
        this_player()->move_player(HAWK"room1-19","SNEAK");
        return 1;
}
