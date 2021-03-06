#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "昭庆寺" );
        set_long("EMPTY\n",
@LONG
你走进一座寺庙，庙堂上挂著一方匾额「昭庆寺」，虽然这座寺庙位居古梅镇
的闹市，但它却出奇的破旧，连殿上大佛的金身也剥落的差不多了，不过，隐约从
殿中传来得几声清磬、几句梵唱却使得你俗念尽消。
LONG
        );
        
        set( "exits", ([ 
		"north" : Goomay"col11",
        ]) );
        
        set( "objects", ([
                "little monk" : Mob"little_monk",
        ]) );
        reset();
#include <replace_room.h>
}

