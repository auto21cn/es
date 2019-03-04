#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("mahogany axe","盘古之斧");
	add ("id",({ "axe"}) );
        set_short("盘古之斧");
	set_long(@C_LONG
一把古老的青铜铸桃木握把小斧，对降妖伏魔有其独特之处。	
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("axe", 25,18,25);
	set( "weight", 150 );
	set( "value", ({ 1430, "silver" }) );
}

