#include "forest.h"
 
inherit ROOM;
 
void create()
{
  ::create();
  set_short("黑森林一角");
  set_long(@CLong
这里是黑森林的一角, 比较特别的是, 这边有著一点点的光亮。光穿
过密林中的隙缝, 照出一条小径。而在小径的末端, 一个略为突起的小平
台(plate) 在黑暗中发著光, 向你招著手。
CLong
        );
        set("exits",([
        "west"      : HERE"3n2w",
        "southeast" : HERE"2n",
        "plate"     : RUIN"plate",
    ]));
//        set("pre_exit_func", ([
//                "plate" : "go_plate",
//        ]) );
    set("objects", ([ "ammunt" : MOB"ammunt", ]) );
        set("exit_suppress", ({ "plate", "west", }) );
//        set("exit_msg", ([
//                "plate" : "@@go_plate",
//        ]) );
        ::reset();
}
 
void init()
{
        add_action("to_look", "look");
        add_action("go_plate","plate");
}
 
int to_look(string arg)
{
        if( arg != "plate" ) return 0;
        write("从这边看过去那块平台似乎不大, 不过去那里看看应该会有所帮助才对。\n");
        return 1;
}

int go_plate()
{
        tell_room( environment(this_player()),
                this_player()->query("c_name")+"向那块平台走去。\n"
                , ({this_player(),this_object()}) );
        this_player()->move_player(RUIN"plate","SNEAK");
        return 1;
}

