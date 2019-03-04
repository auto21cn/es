#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("林间小径");
    set_long(@LONG
没想到狭隘的山壁之外，展现在面前的竟是一片宽广的树海。这儿的风
和缓多了，不像狭道中那般强劲可怕；四处传来的是一连串的悦耳鸟鸣，偶
而出现几声令人胆寒的低鸣，不知道何处会出现可怕的怪物呢！
LONG
             );
    set("exits",([
            "southwest":AREA"gangway2",
            "east":AREA"way2",
            "north":AREA"way3"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
