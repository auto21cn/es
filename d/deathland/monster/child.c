
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(4);
	set_name( "Dwarf child", "矮人小孩" );
	add ("id", ({ "child", "dwarf", }) );
	set_short( "Dwarf child", "矮人小孩" );
	set_long(
	"   \n",
    "当你注视他时，他突然回头向你作鬼脸。\n");

    set( "alignment",-10);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "str", 5 );
	set ("wealth", ([ "silver": 5 ]) );
	set_natural_weapon(2,1,4);
	set_natural_armor(20,0);
    set("weight", 200);
	wield_weapon(Weapon"/shortsword01");
}
