#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson robe", "鲜红色护袍" );
	set_short( "鲜红色护袍" );
	set_long(@CLONG
这是一件用鲜红色布料做成的护袍，在护袍的背面画满了许多奇异的\n"
符号，看起来十分诡异 ....\n"
CLONG
         	);
	add("id",({"robe"}));
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 4 );
    set( "special_defense",
          ([ "evil":5, "mental":-3, "divine":-5 ]) );
	set( "weight", 90 );
	set( "value", ({ 470, "silver" }) );
}
