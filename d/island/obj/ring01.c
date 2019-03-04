#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Sapphire Ring","蓝宝石戒指" );
	add( "id", ({ "ring" }) );
	set_short( "蓝宝石戒指" );
	set_long(@LONG
	圣骑士专用的戒指。上面还镶著一个蓝宝石，更显出
	它的高贵。
LONG
           );
	set( "unit","只" );
	set( "weight",5 );
	set( "type","finger" );
	set( "material","element" );
	set( "defense_bonus",10 );
	set( "soecial_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
