#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Visor","银色面罩" );
	add( "id", ({ "visor" }) );
	set_short( "银色面罩" );
	set_long(@LONG
	一顶闪耀著银色光芒的面罩。
LONG
           );
	set( "unit","顶" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","light_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",0 );
	set( "value",({ 790,"silver" }) );
}
