#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "totem shield", "图腾盾" );
	add( "id", ({ "shield" }) );
	set_short( "图腾盾" );
	set_long(@C_LONG
这面盾是用某种你从没见过的奇特金属制成的，上面画满了各种色彩鲜艳
的符文与图形，在战斗中可以让敌人心生畏惧。
C_LONG
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "armor_class", 7 );
	set( "special_defense", ([ "mental":5 ]) );
	set( "weight", 180 );
	set( "value", ({ 1750, "silver" }) );
}
