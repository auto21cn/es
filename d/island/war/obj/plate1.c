#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronze Plate","青铜铠甲" );
	add( "id", ({ "plate" }) );
	set_short( "青铜铠甲" );
	set_long(@LONG
	这是一件用青铜片编成的战甲，虽然稍微笨重
	一些，但它可是保命的好东西喔。
LONG
           );
	set( "unit","件" );
	set( "weight",220 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",30 );
	set( "defense_bonus",3 );
	set( "value",({ 1440,"silver" }) );
}
