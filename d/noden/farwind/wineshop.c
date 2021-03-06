//#pragma save_binary

#include "/d/noden/farwind/farwind.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";
inherit DOORS;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "小酒店" );
        set_long(@C_LONG
这里是远风镇最有名的酒店，长久以来，冒险家们在这里
休息，互相换取著比金钱还宝贵的经验。游吟诗人在轻轻著唱
著古老的旋律，火炉中的火烧得正烈。这时，没有什麽比来一
杯烈酒更好的了。老经验的人都知道这里卖些什麽，不过你还
是可以跟老板娘要份菜单(menu)来看看!
C_LONG
        );
        
        set( "exits", ([ 
        	"south" : FARWIND"bazz1" ,
        ]) );
        set_inventory( ({
                       ({ FARWIND"items/ching.c", 10, 10}),
                       ({ FARWIND"items/xo.c", 10, 10}),
                       ({ FARWIND"items/rose.c", 10, 10}),
					   ({ FARWIND"items/vodka.c", 10, 10}),
					   ({ FARWIND"items/chicken.c", 10, 10}),
					   ({ FARWIND"items/special.c", 20, 20}),
        }) );
        create_door("south","north",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木门",
		     "c_desc"  : "这是一扇可爱的小木门，门上挂了一个酒店的招牌",		
		     "status"  : "open",
		]) );

        set( "objects", ([
                "shop owner" : FARWIND"monster/wineshop_owner",
                "drunk": FARWIND"monster/drunk"
        ]) );
        reset();
}

void reset()
{
     room::reset() ;
     seller::reset() ;
     return ;
}
