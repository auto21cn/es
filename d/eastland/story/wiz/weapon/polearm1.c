#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden polearm","黄金长矛");
	add ("id",({ "polearm"}) );
        set_short("黄金长矛");
	set_long(@C_LONG
这是一把全身金黄色的长矛。虽然拿起来很沈重，前端矛头却异常锋利，不失为一
把好武器。  
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("polearm", 30,19,30);
	set( "weight", 150 );
	set( "value", ({ 1000, "silver" }) );
}

