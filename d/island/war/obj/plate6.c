#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Acton","白金锁子甲" );
	add( "id", ({ "acton" }) );
	set_short( "白金锁子甲" );
	set_long(@LONG
	一件用白金打造的锁子甲。
LONG
           );
	set( "unit","件" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",35 );
	set( "defense_bonus",2 );
	set( "value",({ 2670,"silver" }) );
}
