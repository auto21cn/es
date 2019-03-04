#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("3xgi", "三叉戟");
  add("id", ({"3xgi"}) );
  set_short("3xgi","三叉戟");
  set_long(
   "一把三叉戟，看来得需很大力气才用的顺手。\n"
  );
  set( "unit", "把" );
  set( "weapon_class", 30 );
  set( "type","thrusting");
  set( "min_damage", 15 );
  set( "max_damage", 25 );
  set( "weight", 100 );
  set( "value", ({ 1000, "silver" }) );
}
