
#include "../echobomber.h"

inherit ROOM;
void create()
{
	::create();
 set_short("","二皇子艾尔的起居室");
  set_long(@Long
Long
,@CLong
这里是二皇子艾尔的起居室 . 一大堆奇奇怪怪的空瓶子\摆\在书桌(desk)上, 另外还
有十几个书柜(closet)放在这个房间中.你觉得这里好像是一座图书馆而不像是一个皇子
的住处.
CLong
);

set("c_item_desc",([
    "desk":"上面\摆\满了一堆空瓶子.你觉得那些瓶子应该是某些实验所留下的.\n",
    "closet":"堆满了一些用古文字所写的书.\n",
    "book":"古文字写的书\n"
    ]) );
    
set("exits",([
              "north":Deathland"/palace/pa_05",
             ]));
#include <../replace_room.h>
}
