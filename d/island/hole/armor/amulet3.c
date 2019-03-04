#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Dragon bone","龙骨" );
	add( "id", ({ "bone" }) );
	set_short( "龙骨" );
	set_long(@LONG
	据说是龙身上最重要的一块骨头，有神圣力量
	保护。
LONG
           );
	set( "unit","块" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",6 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
