#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("long sword", "长剑");
	add( "id", ({ "sword" }) );
	set_short( "钢铸长剑" );
	set_long(
		"这种钢剑是诺达尼亚侍卫队的制式武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 70 );
	set( "weapon_class", 18 );
	set( "type", "longblade" );
	set( "min_damage", 8 );
	set( "max_damage", 19 );
	set( "value", ({ 480, "silver" }) );
}
