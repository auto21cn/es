#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden jousting","黄金枪");
	add ("id",({ "jousting"}) );
        set_short("黄金枪");
	set_long(@C_LONG
这是一把全身金黄色的长枪。黄金枪是「巫咸国」标准的武器，也只有「巫咸国」
才会用黄金来铸造武器。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("jousting", 25,14,24);
	set( "weight", 150 );
	set( "value", ({ 1500, "silver" }) );
}

