#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("captain's hook","太皓古弋");
	add ("id",({ "hook"}) );
        set_short("太皓古弋");
	set_long(@C_LONG
一把青铜参杂著天然精铁所打造的长型武器。它的前端锋锐已极，吹毛断金，无所
不利，是把绝世无双的兵器。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("thrusting", 45,28,47);
	set( "weight", 230 );
        set( "special_things",1);
	set( "nosecond",1);                                                     
	set( "value", ({ 3000, "silver" }) );
}

