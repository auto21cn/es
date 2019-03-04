
#include <zeus.h>

inherit ROOM;
inherit DOORS;
void create()
{
  ::create();
  set_short("酒境");
  set_long(@CLong
这是一间充满酒味的房间，由於密闭式的设计，这里没有留下任何的通风孔
所以除了门之外，四周都是光秃秃的岩壁，地上摆\置著许\许\多多的酒□子，大小
不同形状也千奇百怪，真不知道到底这里藏了多少种的酒．南边是一道钢铸的铁
门．
CLong
); 

set("exits",([
             "south":ZROOM"/wineroom02"
             ]));
create_door("south","north",([
            "keyword":({"gate"}),
            
            "name"   :"iron gate",
            "c_desc" :"一道厚重的铁门",
            "c_name" :"铁门",
            "status" :"locked",
            "lock"   :"WINEROOM_DOOR",
            ]));
  set("objects",([
                 "drunk" : ZMOB"/mine_drunk",
                 "wine#1" : ZOBJ"/da_chu",
                 "wine#2" : ZOBJ"/da_chu"
                 ]));
reset();

}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#15");
}
