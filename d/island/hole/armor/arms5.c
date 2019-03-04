#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Scale Arms","火麟护臂" );
	add( "id",({ "arms" }) );
	set_short( "火麟护臂" );
	set_long(@LONG
	这是一对臂环，每个臂环上都镶著一片火麒麟
	的鳞片。
LONG
           );
	set( "unit","双" );
	set( "weight",50 );
	set( "type","arms" );
	set( "material","leather" );
	set( "armor_class",5 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":25 ]) );
	set( "value",({ 570,"silver" }) );
//	set( "no_sale",1 );
}
