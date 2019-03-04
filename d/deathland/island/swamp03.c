
#include "../echobomber.h"

inherit ROOM;

void bottle_find();
int bottle_num;

void create()
{
	::create();
  set_short("swamp of GreyIsland","灰暗之岛的沼泽");
  set_long(@Long
Long
,@CLong
一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你必须小心谨慎
你的每一步. 越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮住了. 这
地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经快深陷於沼泽里了.

CLong
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
     "northeast":Deathland"/island/swamp04",
     ]) );
set("exit_invisble",1);     
::reset();
}

void init()
{
     bottle_find();

}

void bottle_find()
{
     object *items;
     int i;
     
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/crystal_card"))
             write("你的水晶卡片在这里忽然一阵震动, 似乎这里有著一个神秘的物品.\n");

     return;
}

string search_here()
{
     object *items;
     int i;
     
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/crystal_card")){
             items[i]->set("quest_item/black_bottle",1); 
             return "在沼泽里你发现了一个黑色的瓶子\n";
             } 
     return "似乎沼泽里有些什麽? 但是那是有用的物品吗? \n";        
}
