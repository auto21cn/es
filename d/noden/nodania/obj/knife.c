#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("knife", "小刀");
	set_short("生锈的青铜小刀");
	set_long(@CLONG
一把生满铜绿的青铜小刀，这把小刀也许是价值连城的古董，但是拿
来当武器未免....。
CLONG
      	       );
	set( "weight", 50 );
	set( "type", "dagger" );
	set( "weapon_class", 6 );
	set( "min_damage", 5 );
	set( "max_damage", 14 );
	set( "second", 1 );
	set( "value", ({ 150, "gold" }) );
}
