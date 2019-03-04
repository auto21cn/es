#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Holy helm","圣冠" );
	add( "id", ({ "helm","helmet" }) );
	set_short( "圣冠" );
	set_long(@LONG
	雕刻历代圣者之名的头冠，戴在头上可以受到
	圣者的保护。
LONG
		);
	set( "unit","顶" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","light_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "evil":20 ]) );
	set( "value",({ 3650,"silver" }) );
}
