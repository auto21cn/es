//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("观雨楼");
  set_long( @CLong
你走到这儿，看到一座城楼，城楼门旁挂著一个牌子，写著「观雨楼」。进了楼
里，则是一个放置了许\多书柜、棋盘和桌椅的大厅，四周的墙上则都是一些花鸟、山
水画。角落一个小茶几上放了三套茶具。这儿给你的感觉像是牧马关官兵的休闲中心
。往上是军官室，往西可以回到城墙通道上。
CLong
);
set("light",1);
set("exits",([
               "west":MUMAR"wall03",
               "up":MUMAR"stage03"
             ]));
#include <replace_room.h>
}
