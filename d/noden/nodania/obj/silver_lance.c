#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silver lance", "银枪" );
	add( "id", ({ "lance" }) );
	set_short( "银枪" );
	set_long(@CLONG
这是一把闪亮的银色长枪，大部分擅於使用戳刺型武器的骑士们都喜欢
这样的武器。
CLONG
	);
	set( "unit", "把" );
	set( "type", "thrusting" );
	set( "weapon_class", 30 );
	set( "min_damage", 17 );
	set( "max_damage", 37 );
	set( "weight", 150 );
	set( "value", ({ 1500, "silver" }) );
}
