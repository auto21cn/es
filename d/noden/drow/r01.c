#include "iigima.h"
inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short( "gate","禁地之门");
        set_long(
@C_LONG
这里是黑暗精灵村的禁地，前方传来阵阵的奇怪声响，以及哀嚎声
你必须拿出万全的心里准备，因为，不知名的恐怖可能随时会到来。
C_LONG
        );

        set( "exits", ([
                   "northeast": DROW"r37",        
                   "south": DROW"r04",
        ]) );
        create_door( "south", "north", ([
                "keyword" : ({ "iron door", "door" }),
                "name" : "iron door",
                "c_name" : "大铁门",
                "c_desc" : "一扇冷冰冰的铁门。\n",
                "status" : "locked",
                "lock" : "IRON_DOOR"
        ]) );         
}
