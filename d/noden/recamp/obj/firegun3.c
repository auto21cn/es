#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("fire gun", "神火枪");
  add("id", ({"fire gun","gun"}) );
  set_short("fire gun","神火枪");
  set_long(
   "一把奇妙的枪。\n"
  );
  set( "unit", "把" );
  set( "weapon_class", 45 );
  set( "type","polearm");
  set( "min_damage", 15 );
  set( "max_damage", 25 );
  set( "weight", 100 );
  set( "value", ({ 1000, "silver" }) );
}
