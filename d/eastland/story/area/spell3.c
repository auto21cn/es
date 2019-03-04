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
全的地方。
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
        set("pre_exit_func",([
          "northdown" : "do_northdown",
                 "nd" : "do_northdown"
        ]) );
	set("exits", ([
            "southup" : SAREA"spell2",
          "northdown" : SAREA"spell4",
                 "su" : SAREA"spell2",
                 "nd" : SAREA"spell4"
        ]) );
        set("objects", ([
         "dragon" : SMOB"dragon1"
        ]) ); 
	reset();
}
void init()
{
   add_action("do_auction","auction");
}
int do_northdown()
{
   if ( present("thunder dragon",this_object()) ) {
      write("\n应龙阻止你向北而行！\n\n");
      return 1;
   }      
   return 0;
}
int do_auction(string arg)
{
   write("\n这里忽然起了阵咒语，令你无法专注於拍卖动作！\n\n");
   return 1;
}