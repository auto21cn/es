#include "goomay.h"
inherit DOORS;
inherit ROOM;

void create()
{
        ::create() ;
        set_short("牢房" );
        set_long(
@LONG
这里是捕快们关犯人的地方，犯了案的犯人都关在这里，简简单单的
牢房里只有一张稻草铺成的床，牢房中充斥著霉腐与死亡的气息，。这里
黑黝黝的，空气又差，你真想赶快出去。
LONG
        );
        
        set( "exits", ([ 
		"south" : Goomay"jail",
        ]) );
        set( "objects", ([
                "prisoner1" : Mob"prisoner1",
                "prisoner2" : Mob"prisoner1",
        ]) );
        
        set("c_item_desc",(["bed":"一张简单的稻草床。\n" ]));

      create_door("south","north",
            ([  "keyword" : ({"door","gate"}),
                "name"    : "Iron door",
                "c_name"  : "铁栅门",
                "c_desc"  : "这是一扇有著粗大铁栏的铁栅门",
                "status"  : "open",
                "lock"    : "JAIL_DOOR",
                ]) );

        reset();

}

