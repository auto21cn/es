#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Scute","银色鳞甲" );
	add( "id", ({ "scute" }) );
	set_short( "银色鳞甲" );
	set_long(@LONG
	一件闪耀著银色光芒的鳞甲。
LONG
           );
	set( "unit","件" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","light_metal" );
	set( "armor_class",23 );
	set( "defense_bonus",2 );
	set( "value",({ 800,"silver" }) );
}
