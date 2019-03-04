#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『八哩八哩农场』");
    set_long(@LONG
这里是『八哩八哩农场』，放眼望去看不到任何的土壤，所有的蔬菜都是用
一个小杯子装著，并且漂浮在空中；上方围绕著一层魔法壁，用以过滤大气中的
杂质及防止热度散失。你对这儿神奇的一切产生极高度的兴趣。
LONG
            );
    set_outside("island");
    set("objects",(["farmer":TMOB"farmer"]) );
    set("exits",([
        "west":CITY"farm4",
        "south":CITY"w2"]) );
    reset();
#include <replace_room.h>
}
