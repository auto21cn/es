#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Armbands","守卫识别臂环" );
	add( "id",({ "armbands" }) );
	set_short( "守卫识别臂环" );
	set_long(@LONG
	臂环。
LONG
           );
	set( "unit","双" );
	set( "weight",8 );
	set( "type","arms" );
	set( "material","light_metal" );
	set( "defense_bonus",2 );
	set( "value",({ 570,"silver" }) );
}
