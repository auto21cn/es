
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("well","废弃的监狱");
  set_long(@Long
Long
,@CLong
一处非常破旧的地方,充满了蜘蛛网和灰尘,而在墙角边有一具巨大的骨骸(skeleton)
和一副铁铐.似乎这里应该是个监狱.这另一边的墙角有一个阶梯(stair),似乎可以通向较
高的地方而离开这里.
CLong
);

set("c_item_desc",([
    "stair":"一个阶梯,通向上层的房间.\n",
    "skeleton":"一个巨大的骨骸,由大小来判断应该是巨人的骨骸\n",       
    "wall" : "一片黑漆漆的墙壁,上面有著奇怪的文字,似乎是巨人族的文字\n"       
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );

set("exits",([
     "northeast":Deathland"/dwarf/well05",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_climb","climb");
}

int to_climb(string str)
{
    if(!str||str!="stair") return 0;
    else {
      this_player()->move_player(Deathland"/dwarf/prison02","SNEAK","");
      return 1;
      }
}

string to_search_skeleton()
{
   return "你发现这具骨骸的手好像在墙壁上画些甚麽\n";
}
