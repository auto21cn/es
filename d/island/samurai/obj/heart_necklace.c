#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "heart necklace","心形项链");
        add( "id", ({ "necklace","amulet","heart" }) );
        set_short("heart necklace","心形项链");
        set_long(@AAA
一个心形项链,据 威 说这是他女友送他的定情之物
AAA
        );
        set( "unit", "件"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set("material","element");
        set( "weight", 50 );
        set( "value", ({ 1000, "silver" }) );
}
