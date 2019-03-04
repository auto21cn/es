#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Helmet","钛合金覆面" );
	add( "id", ({ "helmet" }) );
	set_short( "钛合金覆面" );
	set_long(@LONG
	圣骑士专用的头盔，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","件" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",1 );
	set( "special_defense",([ "fire":5 ]) );
	set( "value",({ 1370,"silver" }) );
}
