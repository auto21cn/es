

#include <zeus.h>

inherit ROOM;
int magic_metal;
void create()
{
  ::create();
  set_short("储藏室");
  set_long(@CLong
你来到一个堆满原始矿石的储藏室，有些矿石看起来毫不起眼，但是却是
制造武器的绝佳材料，也许你可以在此地找到传说中的魔法磁铁矿．
CLong
);
   

set("exits",([
             "north":ZROOM"/mine13"
             ]));
set("objects",([
             "iron troll":ZMOB"/iron_troll" ]) );
reset();
}

void init()
 {
    add_action("do_search","search");
 }    
void reset()
 {
   ::reset();
   magic_metal=1;
 }  
 int do_search()
 {
        object obj;   
      if(present("troll")) {
      write("你看见巨人以很不友善的眼光注视著你．．．你急急忙忙地\n");
      write("翻动矿石寻找著，却一无所获．\n");
      tell_room(this_object(),(
      this_player()->query("c_name")+"很急忙地搜索了一遍，露出了失望的表情！\n"),
               this_player() );
               return 1;
      }
     if (magic_metal){
       write("你仔细寻找一遍，终於在墙角找到一块黑黑的石头．\n");
       tell_room(this_object(),(
           this_player()->query("c_name")+"突然露出惊喜的表情!\n"),
           this_player() );       
       obj=new(ZOBJ"/magic_metal.c");
       obj->move(this_object());
       magic_metal =0;
       return 1;
                     }
     else
     {
       write("你上上下下找了好久，就是没有发现任何东西！\n");
       return 1;
     }
 }
