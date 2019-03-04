#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Blood Plate","黑面血甲" );
	add( "id", ({ "plate" }) );
	set_short( "黑面血甲" );
	set_long(@LONG
	为了得到黑暗的加护，用黑血染成的铠甲，是
	战场上的不祥物之一。
LONG
           );
	set( "unit","件" );
	set( "weight",110 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",38 );
	set( "defense_bonus",3 );
	set( "value",({ 2250,"silver" }) );
}
