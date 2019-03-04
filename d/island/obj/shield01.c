#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Shield","钛合金盾" );
	add( "id", ({ "shield" }) );
	set_short( "钛合金盾" );
	set_long(@LONG
	圣骑士专用的盾牌，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","面" );
	set( "weight",60 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 3125,"silver" }) );
}
