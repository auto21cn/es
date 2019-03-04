#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Earth Plate","大地铠甲" );
	add( "id", ({ "plate" }) );
	set_short( "大地铠甲" );
	set_long(@LONG
	由大地之母力量保护的铠甲，据说只要大地存
	在，就不会受损害。
LONG
	);
	set( "unit","件" );
	set( "weight",120 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",36 );
	set( "defense_bonus",3 );
	set( "value",({ 6400,"silver" }) );
}
