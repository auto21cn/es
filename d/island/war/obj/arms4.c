#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Armbands","白金护臂" );
	add( "id", ({ "arm","armband" }) );
	set_short( "白金护臂" );
	set_long(@LONG
	一对用白金打造的护臂。
LONG
           );
	set( "unit","对" );
	set( "weight",9 );
	set( "type","arms" );
	set( "material","knight" );
	set( "armor_class",3 );
	set( "defense_bonus",2 );
	set( "value",({ 1175,"silver" }) );
}
