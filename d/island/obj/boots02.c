#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Boots","钛合金战靴" );
	add( "id", ({ "boots" }) );
	set_short( "钛合金战靴" );
	set_long(@LONG
	圣骑士专用的战靴，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","双" );
	set( "weight",30 );
	set( "type","feet" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2780,"silver" }) );
}
