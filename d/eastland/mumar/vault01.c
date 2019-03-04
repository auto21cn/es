#include <mumar.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("库房");
  set_long( @CLong
这里是牧马关的武器库的保养中心，地上墙上杂乱地放了许\多等待修复的破损武
器和装备，还有一些简单克难的打铁、修补器材。不论要修的东西有多少，这儿的工
匠师父们总是能在最短的时间内完成工作，以供军需。东边出去是教场，西边则还有
一间内室。　
CLong
);
set("light",1);
set("exits",([
               "west":MUMAR"vault00",
               "east":MUMAR"vault02",
             ]));
 
create_door( "west","east",
           (["keyword" : ({"copper","door"}),
             "name"    : "copper door",
             "c_name"  : "铜门",
             "c_desc"  : "一扇铜门。\n",
             "status"  : "closed"
           ]) );
reset();
}
