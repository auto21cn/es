#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long blade", "长刀" );
	add( "id", ({ "blade", }) );
	set_short( "长刀" );
	set_long(
		"这是般若堂武僧使用的长刀, 刀身宽而长, 是少林中常见的兵器。\n" 
	);
	set( "unit", "柄" );
	set( "type", "longblade" );
	set( "weight", 130 );
	set( "weapon_class", 22 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "value", ({ 490, "silver" }) );
}
