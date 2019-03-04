#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "巨剑" );
	add( "id", ({ "bastardsword", "sword" }) );
	set_short(  "火狼之剑" );
	set_long(@C_LONG
这是一把很大、非常大、大到你必须用两只手才能「拿」在手上的巨剑，
它的剑刃上刻有一头火狼的标志，看起来酷毙了！
C_LONG
               );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 38 );
	set( "min_damage", 21 );
	set( "max_damage", 43 );
	set( "weight", 230 );
	set( "nosecond", 1 );
	set( "value", ({ 210, "gold" }) );
}
