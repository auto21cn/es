#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wind boots", "清风靴" );
	add( "id", ({ "boots" }) );
	set_short( "清风靴" );
	set_long( 
@C_TOPIC
这是风之护卫所穿的靴子，闪耀著浅紫色的光芒。
C_TOPIC
	);
	set( "unit", "双" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 6 );
	set( "defense_bonus", 2 );
	set( "extra_skills", ([ "dodge" :15 ]) );
	set( "extra_stats", ([ "pie":-1 ]) );     
	set( "weight", 25 );
	set( "value", ({ 1600, "silver" }) );
}
