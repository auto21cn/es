#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
这是一处透著些许微光线的阴暗洞穴。从上面吹进来的风在地上发出「咻咻咻
」的声音；在空中，好似有人正在对著你嘲笑并且发出桀桀的笑声，那异样的感觉
，不禁令你毛骨悚然冷汗直流；忽然，不知道你踢到什麽东西，低头一看，竟然是
一堆白骨！看来这不是个良善的地方，你还是快离开这里为妙。咦，怎麽脚底下□
□的？吓，原来是从左边的墙壁底下流出些许血水，令这里益发显得恐怖。
LONG
	);
	set("exits", ([
           "east" : SAREA"vhole1"
        ]) );
        set("objects", ([
          "bat#1" : SMOB"bat1",
          "bat#2" : SMOB"bat1",
          "bat#3" : SMOB"bat2",
          "bat#4" : SMOB"bat1",
          "bat#5" : SMOB"bat2",
        ]) );
        set( "c_item_desc", ([
          "crack" : "一个十寸大的裂缝，似乎可以挤(squeeze)进去。\n"
        ]) );
	reset();
}
void init()
{
    add_action("do_auction","auction");
    add_action("do_search","search");
    add_action("do_squeeze","squeeze");
}
int do_squeeze(string arg)
{
    if ( !arg || arg!="crack" )
       return notify_fail("你想把身子挤进那里去？\n");
    write("你把身子挤进左边墙壁的一个裂缝中。\n");
    this_player()->move_player(SAREA"waterfall1",({
       "%s把身子挤进入了一个裂缝中。\n",
       "%s从裂缝外面走了进来.\n"}),"");
    return 1;
}
int do_search(string arg)
{
    write("你发现左壁有几条裂缝(crack)，原来地上的血水是从那里来的！\n");
    return 1;
}    
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
        write("这里受妖法控制使得你无法做这样动作！\n");
    return 1;
}
int clean_up()
{
    return 0;
}