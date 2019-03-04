#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronze Shield","青铜盾" );
	add( "id", ({ "shield" }) );
	set_short( "青铜盾" );
	set_long(@LONG
	这是一面用青铜打造的盾，在盾的边缘还镶有
	一些蓝宝石，这类型的盾是蜥蜴人骑士的标准
	配备。
LONG
           );
	set( "unit","面" );
	set( "weight",150 );
	set( "type","shield" );
	set( "material","knight" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "value",({ 1260,"silver" }) );
}
