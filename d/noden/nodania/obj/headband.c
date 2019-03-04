#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name("headband", "必胜头巾");
	set_short("必胜头巾");
	set_long(
		"这是一条白色头巾，上面写著「必胜」。\n"
	);
	set( "unit", "条" );
	set( "type", "head" );
	set( "armor_class", 3 );
	set( "defense_bonus", 5 );
	set( "value", ({ 3100, "gold" }) );
	set( "weight", 40 );
	set( "no_sale", 1);
}
