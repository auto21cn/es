#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson ring", "鲜红色戒指" );
	add( "id", ({ "ring" }) );
	set_short( "鲜红色戒指" );
	set_long(
		"这是一个鲜红色金属戒指，上面镶著一颗红宝石。\n"
	);
	set( "type", "finger" );
	set( "material", "element");
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense",
	     ([ "evil":5, "electric":5, "energy":5, "divine":-7 ]) );
	set( "weight", 10 );
	set( "value", ({ 920, "silver" }) );
	set( "no_sale", 1 );
}
