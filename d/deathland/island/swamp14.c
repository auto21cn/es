
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("swamp of GreyIsland","灰暗之岛的沼泽");
  set_long(@Long
Long
,@CLong
一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你必须小心谨慎
你的每一步. 这里沼泽的水似乎很深, 而且你的视线也被雾几乎完全地遮住了. 这里
你已经无法清楚地看到四周的状况了, 只知道你的脚已经快深陷於沼泽里了. 仔细看
看脚底似乎有著一种奇怪的蘑菇(mushroom)生长著.
CLong
);


set("exits",([
     "south":Deathland"/island/swamp15",
     ]) );
set("item_func",([
    "mushroom":"look_mushroom",
    ]) );
set("exit_invisble",1);     

::reset();
}


void init()
{
    add_action("to_pluck","pluck");
}

int to_pluck(string str)
{
    object *items;
    int i;
    if (!str||str!="mushroom") return 0;
    
    items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ){
          write("你摘了一些蘑菇放入你的黑盒子里.\n");
          items[i]->set("quest_item/grey_mushroom",1);
          return 1;
          }
     write("你看了看这些蘑菇,似乎没有甚麽用途, 顺手把它丢掉了.\n");
     return 1;     
}

int look_mushroom()
{
    this_player()->set_explore("deathland#24");
    write("一种奇怪的灰色蘑菇, 似乎可以摘(pluck)一些来看看\n");
    return 1;
}
