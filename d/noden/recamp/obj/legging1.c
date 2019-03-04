#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gold legging","金护膝");
        add( "id", ({ "legging" }) );
        set_short("Gold legging", "金护膝");
        set_long(@AAA
这是一件用贵重金属打造而成的金护膝，提供严密的保护。
AAA
        );
        set( "unit", "件"); 
        set( "type", "legs" );
        set( "armor_class", 5 );
        set("material","heavy_metal");
	set( "weight", 50 );
        set( "value", ({ 500, "silver" }) );
}
