#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("tan ring","冲霄云指");
        add( "id", ({ "ring" }) );
        set_short( "冲霄云指");
        set_long(@C_LONG
冲霄云指是阳公公和阴婆婆用千年寒冰制成,看上去还有一闪闪的亮光。
C_LONG
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "weight", 5 );
        set( "value", ({ 47, "gold" }) );
}



