#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("铁栅");
       set_long( @Clong
神火炮营的尽头是一片未开发的林区，无数的参天古木，高耸入云，浓密的树荫
之下，散布著盘根错节的枝干，和各式各样的底生植物，这使得在这片林中行走
成为非常吃力的一件事。前人为了打猎方便，在林中开辟了一条窄小的便道，但
最近，不知道发生了什麽事，山寨决定将这一片密林封闭起来，於是在此修筑了
一道铁栅，并驻兵防守。
Clong
          );
 set_outside( "eastland" );
 set("exits",([
               "south":TROOM"cannon",
               "north":TROOM"forest1"
              ]) );
 set("objects",([
               "yang":TMONSTER"yang2"
               ]));
 set( "pre_exit_func", ([
               "north" : "check_good"
               ]));
create_door("north","south",([
             "keyword" : ({"iron prism","prism" }),
             "status" : "closed",
             "c_desc" : "一道厚重的铁栅",
             "c_name" : "铁栅",
             "name":"iron prism",
             "desc":"an iron prism"
              ]) );
reset();
}
int check_good()
{
      if ( wizardp(this_player()) || !present("yang")) return 0;
      if ( (int)this_player()->query("alignment")>-100 ) return 0;
      else {
      tell_object( this_player(),
         "杨志说道: 吾奉公孙先生之命，把守此处，不许为非作歹之徒进入，看汝之\n"
         "长相，绝非善类，速速离开此地，吾可饶你不死........\n");
    return 1;
           }       
} 
int clean_up() { return 0; }