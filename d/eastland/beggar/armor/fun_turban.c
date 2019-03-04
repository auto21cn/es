#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("sun helmet", "至阳头带");
        add( "id", ({ "helmet" }) );
        set_short( "至阳头带");
        set_long(@C_LONG
至阳头带是用一种特殊的布料,然後经过百年烈焰的□练而成的, 制成的机率可说
是千分之一。除此之外,还附有制造者浑厚的元阳内力, 所以用来防火系攻击是最
好不过的一件东西了。
C_LONG
        );
        set("unit","顶");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class",7 );
        set( "defense_bonus", 5 );
        set( "weight", 40 );
        set( "value", ({ 60, "gold" }) );
        set("special_defense",
                     (["fire":5]) );
}



