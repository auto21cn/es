
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("mountain of GreyIsland","灰暗之岛的山岳");
  set_long(@Long
Long
,@CLong
你沿著小径慢慢地来到了山顶上, 这地方实在是个很古怪的场所, 虽说是灰暗岛
的山顶, 但是你却看到你的头顶上有著厚厚的红泥土与岩石, 你也看到你的底下有著
流动快速的河水.
    东边有著一道很强劲的力场阻挡著你继续前进. 那道力场似乎有著一种神奇的力
量, 须要有著特殊的物品方能让你通过.
CLong
);

set("exits",([
     "southwest":Deathland"/island/mountain01",
     "east":Deathland"/island/mountain03",
     ]) );
set("pre_exit_func",([
    "east":"to_east",
    ])); 
 ::reset();
}

int to_east()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if (items[i]->query("quest_item/crystal_card")) {
          write("你的水晶卡与力墙的力量相应,於是你通过了力墙.\n");
          return 0;
          }
    write("你无法通过力墙.\n");
    return 1;   
}
