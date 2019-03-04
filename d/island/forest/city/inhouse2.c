#include "../tsunami.h"

//inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("正殿");
    set_long(@LONG
这儿是正殿，也是遥照天皇平时听取国政，处理朝纲的地方。只见一张
坐垫放在前方稍高的台阶中央，两旁的墙上挂著几张山水画，倒像是魔族全
境的版图，後方的墙上则是平平整整的挂著族徽，象徵著旧时代的光荣。虽
然乍看之下不觉得壮观，但是其恢复帝国的企图，仍是表露无遗。
LONG
             );
    set("exits",([
        "west":CITY"inway3",
        "south":CITY"inhouse3",
        "north":CITY"inhouse1"]) );
    set("light",1);
 /*   create_door("south","north",([
         "keyword":({"oak door","door"}),
         "status":"closed",
         "name":"Oak door",
         "c_name":"橡木门",
         "c_desc":"一扇厚重结实，刻工精美的橡木门"
         ]) );*/
    reset();
}