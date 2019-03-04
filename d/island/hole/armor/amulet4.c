#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Angel Wing","天使翅膀" );
	add( "id", ({ "wing" }) );
	set_short( "天使翅膀" );
	set_long(@LONG
	可发挥神圣力量的天使翅膀，天使会透过这翅
	膀传送力量。
LONG
		);
	set( "unit","对" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",6 );
	set( "special_defense",([ "evil":20,"fire":20 ]) );
	set( "value",({ 1900,"silver" }) );
}
