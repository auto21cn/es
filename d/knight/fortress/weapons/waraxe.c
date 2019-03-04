#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("waraxe", "战斧");
	add( "id", ({ "axe" }) );
        set_short( "战斧" );
	set_long(
		"这种沉重的战斧是专为强壮的战士设计的。\n"
	);
	set( "unit", "把" );
	set( "weight", 110 );
	set( "no_second", 1 );
	setup_weapon( "axe", 17, 10, 20 );
	set( "bleeding", 10 );
	set( "value", ({ 680, "silver" }) );
}
