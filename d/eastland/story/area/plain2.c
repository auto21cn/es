#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草原");
	set_long(@LONG
你来到了一处空旷的草原，西和北边是草原的延伸，南边是大树群，东南方似
乎有些许不太明显的足迹。在草原上长满了些小小的矮花，其颜色鲜□，香味扑鼻
，一群野蜂正悠哉地穿梭其间，恣意采著蜂蜜。你东边是一面千仞高的山壁，上面
突出来大大小小的岩块如叠格子般一层层的井然有序，与其说这山壁是经由石头堆
积起来的！岩块间有许多裂缝，你试了试发现其大小正足可以容纳一只脚的体积。
LONG
	);
	set("light",1);
	set( "exit_suppress", ({
	   "southwest"}) );
	set("exits", ([ 
                "west" : SAREA"plain1",
               "north" : SAREA"plain4",
           "southwest" : SAREA"village1",
        ]) );
        set("objects" , ([
           "boy#1" : SMOB"boy1",
           "boy#2" : SMOB"boy1",
          "girl#1" : SMOB"girl1",
          "girl#2" : SMOB"girl1",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
    write("你发现在在西南边(southwest)的大树群里有条走过的痕迹！\n");
    return 1;   
}