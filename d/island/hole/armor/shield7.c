#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Scale Shield","火麟盾" );
	add( "id", ({ "shield" }) );
	set_short( "火麟盾" );
	set_long(@LONG
	这是一面用材质较轻的金属打造的盾，上面一
	共镶了五片火麒麟的鳞片。
LONG
           );
	set( "unit","面" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":30,"cold":10 ]) );
	set( "value",({ 1440,"silver" }) );
//	set( "no_sale",1 );
}
