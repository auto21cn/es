#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("black tiger boots","黑虎靴");
        add( "id", ({ "boots" }) );
        set_short("黑虎靴");
        set_long(@C_LONG
这双皮靴上绣有一头黑色的老虎，看来炫极了。        
C_LONG
        );
        set("unit", "双");
        set("type", "feet" );
        set("armor_class", 9 );
        set("material","leather");
        set("defense_bonus", 1 );
        set("weight", 30 );
        set("value", ({ 900, "silver" }) );
}
