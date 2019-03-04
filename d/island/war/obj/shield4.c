#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Shield","白金盾" );
	add( "id", ({ "shield" }) );
	set_short( "白金盾" );
	set_long(@LONG
	这是用白金打造的盾。
LONG
           );
	set( "unit","面" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","knight" );
	set( "armor_class",7 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 2710,"silver" }) );
}
