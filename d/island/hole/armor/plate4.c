#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Black Chainmail","黑色铠甲" );
	add( "id", ({ "chainmail","mail" }) );
	set_short( "黑色铠甲" );
	set_long(@LONG
	乌七抹黑的一件护甲，看不出是甚麽材料做的
LONG
           );
	set( "unit","件" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","light_metal" );
	set( "armor_class",20 );
	set( "defense_bonus",2 );
	set( "value",({ 1440,"silver" }) );
}
