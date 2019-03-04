//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("军官寝室");
  set_long( @CLong
你走进了一间军官寝室。房间里除了一张小小的桌子外，就是放置在角落的一张
木床了。桌上放了一盏油灯和一本兵法书，床上的白色床单上整齐地放置著像豆干般
的薄被。你感觉这儿的主人是个一丝不苟的人。从这儿往南可以回到军官办公室。
CLong
);
set("light",1);
set("exits",([
               "south":MUMAR"stage03",
             ]));
set("objects",([
               "general":MOB"hen"]) );
reset();
#include <replace_room.h>
}
