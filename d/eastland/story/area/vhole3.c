#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
这是一处透著些许微光线的阴暗洞穴。从西面吹进来的风在地上绕著圈圈形成
一个小小的龙卷风旋即又飞起以其利锐的前锋刮过墙壁发出「咻咻咻」的声音；在
空中，好似有人正在对著你嘲笑并且发出桀桀的笑声，那异样的感觉，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麽东西，低头一看，竟然是一堆白骨！看
来这不是个良善的地方，你还是快离开这里为妙。
LONG
	);
	set("exits", ([
             "west" : SAREA"vhole1",
        ]) );
	reset();
}
void init()
{
    add_action("do_auction","auction");
    add_action("do_open","open");
    add_action("do_search","search");
}
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
    write("这里受妖法控制使得你无法做这样动作！\n");
    return 1;
}
int do_search(string arg)
{
    if ( query("be_open") )
       write("你发现一口被人打开过的棺材(coffin)。\n");
    else write("你发现一口棺材(coffin)，似乎可以打开(open)。\n");
    return 1;
} 
int do_open(string arg)
{
    object ob;
    if (!arg||arg!="coffin") return notify_fail("你要打开什麽东西?\n");
    if ( query("have_vampire") || query("be_open") ) { 
       write("这口棺材业已被人打开过了。\n");
       return 1;
    }
    write("\n\n忽然，从棺材中蹦出一个僵□！\n\n\n");
    ob=new(SMOB"vampire1");
    ob->move(this_object());
    SAREA"vhole1"->set("have_vampire",1);
    SAREA"vhole2"->set("have_vampire",1);
    SAREA"vhole3"->set("have_vampire",1);
    set("be_open",1);
    return 1;
}
int clean_up()
{
    return 0;
}
void reset()
{
    set("be_open",0);
    ::reset();
}