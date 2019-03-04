#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Protect Ring","加护戒指" );
	add( "id", ({ "ring" }) );
	set_short( "加护戒指" );
	set_long(@LONG
	用和天使之戒相同材料作成的戒指，在圣父名
	下可得到天使的保护。
LONG
		 );
	set( "unit","只" );
	set( "type","finger" );
	set( "material","element" );
	set( "weight",5 );
	set( "value",({ 1750,"silver" }) );
	set( "defense_bonus",6 );
	set( "special_defense",([ "evil":20 ]) );
}
