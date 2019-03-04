#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("教场");
    set_long(@LONG
在这宽广的教场中，只见许多新近入伍的新兵在这儿接受训练；可见得
魔族是多麽担心蜥蜴人和武士团会伺机偷袭了。    
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway2"]) );
    set("objects",([
        "soldier#2":TMOB"soldier01",
        "soldier#1":TMOB"soldier01",
        "warrior"  :TMOB"warrior01"]) );
    reset();
#include <replace_room.h>
}
