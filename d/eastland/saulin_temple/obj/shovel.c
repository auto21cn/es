#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
	set_name("Shovel", "方便铲");
	add ("id",({ "shovel" }) );
	set_short("方便铲");
	set_long(@C_LONG
一把铲子，是方便後用来埋土的。可是它的铲缘十分的锋利，让你不禁
怀疑它到底是工具还是武器。
C_LONG
	);
	set( "weapon_class", 20 );
	set( "type", "blunt" );
	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 50 );
	set( "no_sale", 1);
	set( "value", ({ 50, "gold" }) );
	set( "unit", "把" );
}
