#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronz Bracer","青铜护腕" );
	add( "id",({ "bracer" }) );
	set_short( "青铜护腕" );
	set_long(@LONG
	这是一副用青铜打造的护腕，可以确保你再战
	斗中不会因为手腕受伤而丧失战斗力。
LONG
           );
	set( "unit","副" );
	set( "weight",50 );
	set( "type","hands" );
	set( "material","heavy_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",2 );
	set( "value",({ 450,"silver" }) );
}
