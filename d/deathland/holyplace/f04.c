// Deathland/holyplace/f03.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("dark cave","黑暗的洞穴");
    set_long(@Long
Long
,@CLong
一片漆黑的地方, 除了黑暗还是黑暗, 一个奇异的骇骨横置於洞穴的角落, 你觉
得有个力量似乎控制的地方. 
CLong
);
set("search_desc",([
    "skeleton":"@@to_search_skeleton",
    ]) );
set("item_func",([
    "skeleton":"to_look_skeleton",
    "paper": "to_look_paper",
    ]) );
set("exits",([
             "leave":Deathland"/holyplace/f03",
             ]));
reset();
}

int to_look_skeleton()
{
     write( 
           "似乎这个骇骨已经放在这个地方很久了. 而上面有著一张\n"           
           "符咒(incantation paper)附在上面.\n"
           );
     return 1;        
}

int to_look_paper()
{

    write(
          "一张附於骇骨身上的怪异符咒.\n"
          );
    return 1;      
}

string to_search_skeleton()
{
     object paper,*item,player;
     int i;
     
     player=this_player();
     item=all_inventory(player);
     write( 
            "你搜查骇骨, 没有什麽大发现, 除了那张奇怪的符咒外, 没有其\n"
            "他特别的事物. 於是你就把那张符咒给撕下来\n"
          );
     write(
           "然而当你拿到了符咒之後, 你发现骇骨上又多了一道相同的符咒.\n"
           "令人觉得这符咒似乎有种很强的魔力."
           );
     for(i=0;i<sizeof(item);i++) 
       if ( (string)item[i]->query("name")=="Incantation paper of Lock") 
         return "\n";
     paper=new(Object"/letter03");
     paper->move(this_player());
     return "\n";            
}

