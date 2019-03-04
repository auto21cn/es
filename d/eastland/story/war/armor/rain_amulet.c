#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Rain amulet","雨符");
        add("id",({"amulet"}) );
        set_short("雨符");
	set_long(@C_LONG
一个雨师精制的护符，上绘水滴的形状，整个看上去好似浸在水里一样。
C_LONG	         );
	set( "unit", "个" );
	set( "weight",6 );
	set( "type", "misc" );
        set("material","cloth");
	set( "defense_bonus", 4 );
	set( "special_defense",(["evil":20,"divine":-15]));
	set( "value", ({ 1000, "silver" }) );
}
