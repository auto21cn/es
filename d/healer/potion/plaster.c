#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	set_name("moss plaster", "绿苔膏" );
	add( "id", ({"plaster"}) );
	set_short("绿苔膏");
	set_long(
		"这是用来止血用的绿苔膏，将它敷(apply)在伤口上可以止血。\n"
	);
	set( "can_apply", 1 );
	set( "unit", "团" );
	set( "weight", 40 );
	set( "value", ({ 50, "silver" }) );
}

int apply(object player)
{
	if( !player->query("conditions/bleeding") ) return 0;
	BLEEDING->remove_effect(player);
	return 1;
}
