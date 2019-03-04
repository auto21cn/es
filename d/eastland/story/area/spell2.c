#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
这里是禁地里面的洞穴，空洞洞地似乎没有任何东西。除此之外，你感到这里
非常潮□，空气中还有些发霉的味道，让你混身感到不舒服。在这里，不时听到些
动物的嘶吼声，其声可怖已极，更兼在地上看到一堆骸骨，说明了这实在不是个安
全的地方。南边是禁地，据说，需要具备经过天神祝福的铠甲才能安全无虞地通过
。
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
	set("exits", ([
            "southup" : SAREA"spell1",
          "northdown" : SAREA"spell3",
                 "su" : SAREA"spell1",
                 "nd" : SAREA"spell3",
        ]) );
        set("objects", ([
         "dog#1" : SMOB"dog1",
         "dog#2" : SMOB"dog1",
         "dog#3" : SMOB"dog1",
        ]) );
	reset();
}
void init()
{
   add_action("do_auction","auction");
}
int do_auction(string arg)
{
   write("\n这里忽然起了阵咒语，令你无法专注於拍卖动作！\n\n");
   return 1;
}