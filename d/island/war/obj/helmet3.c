#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Visor","白金面罩" );
	add( "id", ({ "visor" }) );
	set_short( "白金面罩" );
	set_long(@LONG
	一顶用白金打造的面罩。
LONG
           );
	set( "unit","顶" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","knight" );
	set( "armor_class",6 );
	set( "defense_bonus",2 );
	set( "value",({ 1370,"silver" }) );
}
