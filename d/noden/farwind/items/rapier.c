#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "light rapier", "轻型剑" );
	add( "id", ({ "rapier" }) );
	set_short( "轻型剑" );
	set_long(@CLONG
这是一种普通剑士十分喜爱的剑，剑身细长而且易於挥动，剑柄
部份还有金属的护手凹槽。
CLONG
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 12 );
	set( "weight", 60 );
	set( "value", ({ 240, "silver" }) );
}
