
#include <zeus.h>

inherit ROOM;
inherit DOORS;
void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，偶而可以听到人们的吆喝声，从声音中可以听出充满
了兴奋与快乐的味道，一阵阵的酒香隐隐传来，北边是一道钢铸的铁门．
CLong
); 

set("exits",([
             "north":ZROOM"/wineroom03",
             "south":ZROOM"/wineroom01"
             ]));
create_door("north","south",([
            "keyword": ({"gate"}),
            
            "name"   : "iron gate",
            "c_desc" : "一座厚重的铁门",
            "c_name" : "铁门",
            "status" : "locked",
            "lock"   : "WINEROOM_DOOR",
            ]));
            
            set("objects",([
                "guard#1":ZMOB"/wine_guard1",
                "guard#2":ZMOB"/wine_guard",
                ]));
reset();
}