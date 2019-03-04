#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Death Cloak","死神披风" );
	add( "id",({ "cloak" }) );
	set_short( "死神披风" );
	set_long(@LONG
	这是传说中会熄灭生命火焰的披风，只有死神
	才能拥有它。
LONG
           );
	set( "unit","件" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","cloth" );
	set( "armor_class",5 );
	set( "defense_bonus",6 );
	set( "special_defense",([ "fire":25,"cold":10,"none":15 ]) );
	set( "value",({ 975,"silver" }) );
}
