#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_armband", "武士护腕 ");
        add( "id", ({ "armband" }) );
        set_short("samurai_armband", "武士护腕");
        set_long(@AAA
一个武士们制式穿的护腕
AAA
        );
        set( "unit", "件"); 
        set( "type", "arms" );
        set( "armor_class", 3 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 100 );
        set( "value", ({ 650, "silver" }) );
        
}
