
// Deathland/ruin1/house01.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the council","议会");
     set_long(@Long
Long
,@CLong
这里是遗迹的议会 .一处很大的建筑, 四周围著著一排排的座位, 而中间是主席台
与外面的景像比较起来, 这个地方似乎是一个安详的地方, 似乎没有任何肃杀的气氛. 
CLong
);
     set("search_desc",([
         "here":"@@search_here",
         ]) );
     set("exits",([
         "out":Deathland"/ruin1/ruin11",
         ]) );
     set("crystal",1);
     reset();
}

string search_here()
{
    object item;
    if ( query("crystal") ) {
      item=new(Object"/crystal01");
      item->move(this_object());
      this_player()->set_explore("deathland#19");
      set("crystal",0);
      return "当你仔细搜查这里的时候, 你发现了一颗紫色的水晶.\n";
      }  
    return "似乎有人先搜查过这里了.\n";
}

void reset()
{
   ::reset();
   set("crystal",1);
}
