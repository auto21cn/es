#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name( "Long Axe","长柄战斧" );
	add( "id",({ "axe" }) );
	set_short( "长柄战斧" );
	set_long(@LONG
	一把长柄战斧。
LONG
	);
	set( "unit","把" );
	set( "type","axe" );
	set( "weapon_class",32 );
	set( "min_damage",22 );
	set( "max_damage",36 );
//	set( "bleeding",10 );
	set( "weight",150 );
	set( "value",({ 1080,"silver" }) );
}