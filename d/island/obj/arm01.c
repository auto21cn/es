#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Armbands","钛合金臂环" );
	add( "id", ({ "arm","armbands" }) );
	set_short( "钛合金臂环" );
	set_long(@LONG
	圣骑士专用的臂环，是用一种奇特的金属打造而
	成的。虽然是金属材质，但是却不像一般金属那
	麽笨重。
LONG
           );
	set( "unit","对" );
	set( "weight",45 );
	set( "type","arms" );
	set( "material","heavy_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 1175,"silver" }) );
}
