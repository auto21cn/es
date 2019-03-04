#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_gloves ", "武士护手 ");
        add( "id", ({ "gloves" }) );
        set_short("samurai_gloves ", "武士护手 ");
        set_long(@AAA
一个武士们穿在手上的防具
AAA
        );
        set( "unit", "件"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 70 );
        set( "value", ({ 500, "silver" }) );
}
