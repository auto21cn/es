#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("树林");
    set_long(@LONG
这儿四周长满了奇形怪状的植物，大多是目前尚不为人知的。风也已经
和缓多了，不像狭道中那般强劲可怕；四处传来的是一连串的悦耳鸟鸣，偶
而出现几声令人胆寒的低鸣，不知道何处会出现可怕的怪物呢！东边好像有
人居住的样子！
LONG
             );
    set("exits",([
            "east":AREA"house1",
            "southwest":AREA"way2",
            "north":AREA"way5"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
