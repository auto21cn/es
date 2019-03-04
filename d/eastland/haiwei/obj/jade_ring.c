#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "jade ring", "翡翠戒指" );
	add( "id", ({ "ring" }) );
	set_short( "翡翠戒指" );
	set_long("这是一个很漂亮的翡翠戒指。\n");
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "divine" :2 ]) );
	set( "weight", 5 );
	set( "value", ({ 310, "silver" }) );
}
