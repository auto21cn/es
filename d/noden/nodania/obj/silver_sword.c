#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "阔剑" );
	set_short( "银色阔剑" );
	set_long(@CLONG
这是一把巨大、闪亮的银色阔剑，它看起来又重又锐利，只有精通剑术和
力量强大的人能驾驭这样的武器。
CLONG
	);
	set( "unit", "把" );
	set( "weapon_class", 32 );
	set( "type", "longblade" );
	set( "min_damage", 17 );
	set( "max_damage", 38 );
	set( "nosecond", 1 );
	set( "weight", 180 );
	set( "value", ({ 1400, "silver" }) );
}
