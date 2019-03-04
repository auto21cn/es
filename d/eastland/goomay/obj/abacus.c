#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "abacus", "算盘" );
	add( "id", ({ "counter" }) );
	set_short( "算盘" );
	set_long(
		"这是一个乌黑的算盘，只是一般商业用的，看起来不像是武器。\n"
	);
	set( "unit", "个" );
	set( "weight", 100 );
	setup_weapon( "blunt", 25, 10, 20 );
	set( "value", ({ 20, "gold" }) );
        set_c_verbs(({"%s砸向%s","%s推向%s","%s撞向%s"}));

}
