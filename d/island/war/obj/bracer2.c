#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Bracer","银色护腕" );
	add( "id",({ "bracer" }) );
	set_short( "银色护腕" );
	set_long(@LONG
	这是一副闪耀著银色光芒的护腕。
LONG
           	);
	set( "unit","副" );
	set( "weight",45 );
	set( "type","hands" );
	set( "material","light_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",2 );
	set( "value",({ 470,"silver" }) );
}
