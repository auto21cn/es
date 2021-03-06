//#pragma save_binary
 
#include "farwind.h"
 
inherit ROOM;
 
void create()
{
        ::create();
        set_short( "酒窖" );
        set_long(@C_LONG
这里是一间酒窖，即使这里一片漆黑伸手不见五指，你也可以很清
楚地确定这点，因为浓冽的酒味几乎把你给醉倒。角落里有一个生锈的
铁梯子(ladder)，似乎是离开这里唯一的路。
C_LONG
        );
        set( "item_desc", ([
        "ladder" : "这个梯子上面生满了铁锈，似乎这里的主人也很少下来\n"
                   "这个酒窖。梯子的旁边有一个洞(hole)，不知道里面有\n"
                                        "什麽？\n",
        "hole" : "这个洞虽然不大，但是你勉强可以钻进去(enter)。\n"
        ]) );
        set( "exits", ([
                "up" : FARWIND"smithy"
        ]) );
        set( "pre_exit_func", ([
                "up" : "check_ladder"
        ]) );
        set( "objects", ([
                "rat 2" : FARWIND"monster/rat"
        ]) );
        reset();
}
 
void init()
{
        if( this_player()) this_player()->set_explore("noden#1");
        add_action( "enter_hole", "enter" );
}
 
int check_ladder()
{
        object smithy;
 
        smithy = find_object( FARWIND"smithy" );
        if( !smithy || !smithy->query("item_desc/ladder") ) {
                write(
                "你爬到梯子顶端，但是上面似乎被什麽重物压住了，你无法出去。\n"
                );
                return 1;
        }
        return 0;
}
 
 
int enter_hole(string arg)
{
        string name;
        if( !arg || arg!="hole" )
                return notify_fail("进入什麽？\n");
        name=(string)this_player()->query("c_name");
        this_player()->move_player(FARWIND"cellar2",
                name+"爬进梯子旁的一个小洞。\n",
                name+"从一堆箱子後面走了出来。\n"
         );
        return 1;
}
 
