#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "mercenary", "镖师" );
	set_short("镖师" );
	set_long(
		"这些镖师闲来无事，围著一堆正在闲磕牙，一面等著生意上门。\n"
	);
	set( "unit", "名" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 12 );
	set_skill( "dodge", 70 );
	set( "special_defense", ([ "all": 10 ]) );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 40, 16 );
	set_natural_weapon( 13, 9, 16 );
	set( "wealth/gold", 10 );
#include <replace_mob.h>
}
