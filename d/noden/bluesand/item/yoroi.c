#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "yoroi", "战甲" );
   set_short( "日式战甲" );
	set_long(
     "这是一套日式的铠甲，将许多硬化的牛皮用粗绳结起来，然後在重要\n"
		"的部位打上金属片。\n"
	);
	set( "unit", "套" );
	set( "weight", 210 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 25 );
	set( "defense_bonus", 3 );
    set( "special_defense",
           ([ "electric":-3, "acid":2 ]) );
	
	set( "value", ({ 820, "silver" }) );
	set( "no_sale", 1 );
}
