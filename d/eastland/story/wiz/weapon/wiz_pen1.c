#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden pen","金笔");
	add ("id",({ "pen"}) );
        set_short("金笔");
	set_long(@C_LONG
一枝纯金打造的笔管，毛沾金墨，昂贵极了。
C_LONG
	);
	set( "unit", "枝" );
        setup_weapon("thrusting", 30,15,20);
	set( "weight", 100 );
        set("second",1);
        set( "special_things",1);
	set( "value", ({ 2500, "silver" }) );
}

