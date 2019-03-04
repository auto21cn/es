#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Ebony Lance","黑檀木柄长枪" );
	add( "id",({ "lance" }) );
	set_short( "黑檀木柄长枪" );
	set_long(@LONG
	这是蜥蜴人禁卫军专用的长枪，握柄的部份是用
	黑檀木做的，可以算的上是一种高级品。
LONG
		);
	set( "unit","把" );
	set( "type","jousting" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",140 );
	set( "value",({ 2330,"silver" }) );
}