//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("军官寝室");
  set_long( @CLong
你走进了一间军官寝室。房间里除了一张小小的桌子外，就是放置在角落的一张
木床了。桌上放了一盏油灯和一双破鞋，红色床单上的被子则乱七八糟地放置著。墙角
还堆了一些传来恶臭的衣物。你感觉这儿的主人是个一蹋糊涂的人。从这儿往北可以回
到军官办公室。
CLong
);
set("light",1);
set("exits",([
               "north":MUMAR"stage03",
             ]));
set("objects",([
               "general":MOB"ha"]) );
reset();
#include <replace_room.h>
}
