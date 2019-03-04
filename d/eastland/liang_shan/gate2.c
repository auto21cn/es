#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("铁栅");
       set_long( @Clong
你来到一条林间小径，小径的尽头是一道厚重的大铁栅，铁栅旁立了一个大
告示(board)，上面写了一些字。一个黝黑的大汉抱著一把斧头，正躺在告示
下呼呼大睡，发出如雷的鼾声......Z....Z....Z.....
Clong
          );
set ("c_item_desc",([
"board":@Board
 ---------------------------------------------------------------------
  注意    梁山泊禁地
               
                   妄入者死一百次                        宋江
---------------------------------------------------------------------
Board
 ]));
 set_outside( "eastland" );
 set("exits",([
               "north":TROOM"path9",
               "south":TROOM"path8",
              ]) );
 set("objects",([
               "li":TMONSTER"li"
               ]));
 set( "pre_exit_func", ([
               "north" : "check_flag"
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
int check_flag()
{
      if ( wizardp(this_player()) || !present("li")) return 0;
      if ( present("flag",this_player()) ) return 0;
      else {
      tell_object( this_player(),
         "李逵忽然张开眼睛说道: 没有令旗不准进去，说完眼睛一闭，又睡著了...\n");
    return 1;
           }       
}
int clean_up() { return 0; } 