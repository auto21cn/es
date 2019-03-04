
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，比起其他的矿坑，这地方似乎宽大了许\多，四周用
许\多的木条支撑著，地上散布了\许\多巨大的脚印，看起来并不像普通人类所有．
CLong
);
   

set("exits",([
             "south":ZROOM"/bridge",
             "northeast":ZROOM"/center1"
             ]));
reset();
#include <replace_room.h>
}
