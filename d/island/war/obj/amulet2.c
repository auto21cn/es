#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Amulet","白金徽章" );
	add( "id", ({ "amulet" }) );
	set_short( "白金徽章" );
	set_long(@LONG
	古代阶级的徽章之一，就体制流传下来的宝物
	，至今仍俱有高贵的价值。
LONG
           );
	set( "unit","枚" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",4 );
	set( "value",({ 2620,"silver" }) );
}
