
#include <zeus.h>

inherit ROOM;
int paper_num;
void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，偶而可以听到人们的吆喝声，从声音中可以听出充满
了兴奋与快乐的味道，在前方一定有一个让人流连忘返的快乐天堂．
CLong
); 

set("exits",([
             "north":ZROOM"/wineroom02",
             "southeast":ZROOM"/center4"
             ]));

reset();
#include <replace_room.h>
}