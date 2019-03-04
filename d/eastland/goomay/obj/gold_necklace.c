#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("gold necklace","玉坠项□");
        add("id",({"gold","necklace",}) );
         set_short( "a gold necklace","玉坠项□");
	set_long(
"This is a gold necklace \n"
"这是一个由金子打造的项□，□上有个古玉坠子，看起来非常美丽。\n" 
	);
	set( "unit", "串" );
	set( "weight", 12 );
        set("material","light_metal");
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 160, "gold" }) );
}
