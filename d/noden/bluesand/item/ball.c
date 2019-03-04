#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "hankra ball", "汉卡拉之球" );
	add( "id", ({ "ball" }) );
   set_short( "汉卡拉之球" );
	set_long(
		"汉卡拉之球正发出一团柔和的光芒，传说中这种光芒是永恒的、智慧的\n"
		"思想与远古的存在。\n"
	);
	set( "unit", "颗" );
	set( "light", 1 );
	set( "weight", 70 );
	set( "value", ({ 300, "silver" }) );
	set( "no_sale", 1 );
}
