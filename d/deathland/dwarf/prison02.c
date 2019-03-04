#include "../echobomber.h"

inherit ROOM;

int letter;
void create()
{
	::create();
  seteuid(getuid());
  set_short("well","废弃的监狱");
  set_long(@Long
Long
,@CLong
一处非常破旧的地方,充满了蜘蛛网和灰尘,而在墙角边有一具巨大的骨骸(skeleton)
躺在那里.....这另一边的墙角有一个阶梯(stair),似乎可以离开这里.
CLong
);

set("c_item_desc",([
    "stair":"一个阶梯,通向下层的房间.\n",
    "skeleton":"@@to_look_skeleton",
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );

set("exits",([
     "down":Deathland"/dwarf/prison",
     ]) );
 ::reset();
}

void reset()
{
   ::reset();
   letter=0;
}

string to_look_skeleton()
{
   switch(letter) {
   case 0:
   return "一个巨大的骨骸,由大小来判断应该是巨人的骨骸,在他的手上\n"
          "似乎握著一个东西\n";
   case 1:
   return "一个巨大的骨骸,由大小来判断应该是巨人的骨骸\n";
   }
}

string to_search_skeleton()
{
   object ob1;
   switch(letter) {
   case 0:  
     letter=1;
     ob1=new(Object"/letter01");
     ob1->move(this_player());
     this_player()->set_explore( "deathland#4" );
     return "你从骨骸的手中发现了一张破旧发黄的破纸\n";
   case 1:
     return "在一阵仔细的搜索下,你只能确定这是个巨人的骨骸\n"; 
   }  
}
