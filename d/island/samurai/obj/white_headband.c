#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "white_headband", "白头巾");
        add( "id", ({ "headband","white" }) );
        set_short("white_headband", "白头巾");
        set_long(@AAA
一个白色的头巾,上面还有一股汗臭味
AAA
        );
        set( "unit", "件"); 
        set( "type", "head" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 30 );
        set( "value", ({ 300, "silver" }) );
}
