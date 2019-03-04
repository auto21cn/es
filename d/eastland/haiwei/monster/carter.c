#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "carter", "车夫" );
	set_short( "车夫" );
	set_long("这名车夫看起来像是赶了很长的路，他正坐在客栈前的台阶上休息。\n");
	set( "unit", "名" );
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "str", 3 );
	set_natural_weapon( 3, 3, 3 );
	set( "alignment", 200 );
	set( "wealth/gold", 1 );
#include <replace_mob.h>
}
