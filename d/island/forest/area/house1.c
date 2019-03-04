#include "../tsunami.h"

inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("庭院");
    set_long(@LONG
这儿果然有人住著，东方有一间颇为华丽的房子，而这儿看来似乎是庭
院的样子，两旁的花圃整理的十分整齐，中间假山的小瀑布更是让人觉得这
儿的主人品味非常非常出众。不知道房子中住的是什麽样的人呢？
LONG
             );
    set("exits",([
            "east":AREA"house2",
            "west":AREA"way4"]) );
    set_outside("island");
    create_door("east","west",([
         "keyword"   :  ({"Oak door","door"}),
         "status"    :"closed",
         "name"      :"oak door",
         "c_name"    :"橡木门",
         "c_desc"    :"一道有著精致雕刻的橡木门"
                ]) );
    reset();
}
