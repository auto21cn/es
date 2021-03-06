// Deathland/holyplace/f02.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("fire bridge","火桥");
    set_long(@Long
Long
,@CLong
地底的岩浆所冒出的热气正向你侵袭而来,这地方已经相当接近地底了.在你的东边
有一座桥,横跨在这熊熊烈火燃烧的悬崖之上,桥下是熔岩的所在,你无法想像掉下桥下
会有甚麽後果.西边有一个黑黑的洞穴,通往未知的领域.
CLong
);

set("c_item_desc",([
    "cave":"@@to_look_cave",
    "bridge":"@@to_look_bridge",
    ]) );
set("exits",([
             "west":Deathland"/holyplace/f03",
             ]));
reset();
}

void init()
{
     add_action("to_pass","pass");
}

string to_look_cave()
{
     return can_read_chinese() ?
            "一个黑暗的洞穴.\n":
            "need work.\n"; 
}

string to_look_bridge()
{
    return can_read_chinese() ?
          "一座不很牢固的吊桥,而且你能清楚地感觉到桥上的高温是一般人无法\n"
          "忍受的.当然,如果你能忍受如此的高温的话,你可以试著快速地通过这\n"
          "座火桥(pass bridge)看看.\n":
          "need work.\n";
}

int to_pass(string str)
{
    
    int i;
    object player,*item;
    
    if (!str||str!="bridge") return 0;
    
    player=this_player();
    item=all_inventory(player);
    for(i=0;i<sizeof(item);i++) 
      if ( (string)item[i]->query("name")== "Cold oil" && item[i]->query("applied") ) {
        write("你以极快的速度通过了火桥\n");
        player->move_player(Deathland"/holyplace/f01",({
        "%s passes bridge very fast.\n","%s 以极快的速度通过火桥.\n",
        "%s comes here from bridge\n","%s 从火桥上跑了下来.\n"})
        );
        return 1;
        }
    player->receive_special_damage("fire",100);
    write("你的身体被火灼伤了.\n同时你无法忍受桥的高温而退了回来.\n");
    return 1;
}
