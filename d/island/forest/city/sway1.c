#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("石板街");
    set_long(@LONG
这是一条平坦宽广的大街道，魔族的人利用本身已知的搬运魔法来代替
兽力、人力，因此做出来的路面颇为平坦。两旁种满了各式各样的行道树，
连在赶路的你，都忍不住想要驻足欣赏随风摇曳的树影，好让自己紧张的心
情得到些微的放松。
LONG
);
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"school",
        "west":CITY"hill1",
        "south":CITY"sway2",
        "north":CITY"r6"]) );
        reset();
#include <replace_room.h>
}