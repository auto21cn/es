#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Helmet","战神头盔" );
	add( "id", ({ "helmet" }) );
	set_short( "战神头盔" );
	set_long(@LONG
	这头盔和战神铠甲刚好是一套，它是用一种质
	料较轻的金属做成的，能确实保护头部。
LONG
           );
	set( "unit","顶" );
	set( "weight",45 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",2 );
	set( "value",({ 1500,"silver" }) );
//	set( "no_sale",1 );
}
