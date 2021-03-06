#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
        set_name( "staff", "刺杖" );
	add( "id", ({ "staff" }) );
   set_short( "刺杖" );
	set_long(
		"这根木杖上面钉满了尖尖的铁刺，有些刺上还带有倒钩。\n"
	);
	set( "unit", "根" );
	set( "type", "blunt" );
	set( "weapon_class", 9 );
	set( "min_damage", 3 );
	set( "max_damage", 10 );
	set( "weight", 70 );
	set( "value", ({ 40, "silver" }) );
}
