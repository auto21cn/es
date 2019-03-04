// Deathland/fog1.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("Fog","雾中");
    set_long(@Long
Long
,@Clong
一遍大雾把你的视线完全笼罩住了,你的方向感已经完全的失去了
Clong
	);
   set("search_desc",([
       "here":"@@to_search_here",
       "blowhole":"@@to_search_blowhole",
       ]) );
   
   set("c_item_desc",([
       "blowhole":"一些冒著雾气的气孔.\n",
       ]) );
   
   set("exits",([
       "east":Deathland"/fog/fog2",
       "west":Deathland"/fog/fog2",
      // "north":Deathland"/fog/fog2",
      // "south":Deathland"/fog/fog2",
      ]) );
   reset();    

}
void init()
{
    // add_action("","");

}

string to_search_here()
{
   
   return "你仔细的寻找出路的时候,你发现地上充满著一些气孔(blowhole)冒出雾气\n"
          "原来那就是雾不会消散的原因.\n";

}

string to_search_blowhole()
{
  return "这些在地上的气孔的形状千奇百怪,而且排列的位置相当奇怪,似乎形成一种.\n"
         "特殊的符号.\n"; 
}
