#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
	set_name( "branz herb", "布兰兹药草" );
	add( "id", ({ "herb" }) );
	set_short( "布兰兹药草" );
	set_long(
		"据说如果把布兰兹药草敷(apply)在伤口上，会使伤口恢复得比较快。\n"
	);
	set( "unit", "束" );
	set( "heal_apply", 2 );
	set( "duration", 10 );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
