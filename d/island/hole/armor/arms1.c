#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Armbands","战神臂环" );
	add( "id",({ "armbands" }) );
	set_short( "战神臂环" );
	set_long(@LONG
	这是战神五种配备中的臂环。
LONG
           );
	set( "unit","双" );
	set( "weight",10 );
	set( "type","arms" );
	set( "material","heavy_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",4 );
	set( "value",({ 2100,"silver" }) );
//	set( "no_sale",1 );
}