#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("Copper shield", "铜盾");
        add( "id", ({ "shield" }) );
        set_short( "铜盾" );
        set_long(
@C_LONG
这是铜制的盾牌，看来坚实厚重。
C_LONG
        );
        set( "unit", "面");
        set( "type", "shield" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 140 );
        set( "value", ({ 380, "silver" }) );
}
