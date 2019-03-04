#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Gauntlets","钛合金护手" );
	add( "id", ({ "gauntlets","gloves" }) );
	set_short( "钛合金护手" );
	set_long(@LONG
	圣骑士专用的护手，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","双" );
	set( "weight",20 );
	set( "type","hands" );
	set( "material","heavy_metal" );
	set( "armor_class",5 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2890,"silver" }) );
}
