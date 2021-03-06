#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("orc blunt", "兽人权杖");
  add("id", ({"blunt","orc blunt"}) );
  set_short("a orc blunt","兽人权杖");
  set_long(
   "一把黑钢铸成的权杖，上面雕了一只半兽人的雕像。\n"
  );
  set( "unit", "把" );
  set( "weapon_class", 40 );
  set( "type","blunt");
  set( "min_damage", 15 );
  set( "max_damage", 40 );
  set( "weight", 100 );
  set( "value", ({ 8000, "silver" }) );
  set( "hit_func", "weapon_hit" );
  set_c_verbs ( ({
   "%s霎间「一刀两断、夺命三剑客」两式，打在%s",
   "%s霎间「流星斩、赶月铡」两式，攻向%s",
   "%s霎间「十字东征、千军万马」两式，斩向%s",
   "%s霎间「撒旦血盟、恶魔有约」两式，刺向%s",
             }) ) ;
}

int weapon_hit( object victim, int damage )
{
   object owner ;
   int inte ;

   owner = environment();
   inte = owner->query_stat("str");
   if (!victim) return 0;
   if ( random(100) > 80 ) {
     tell_object( owner,
       "\n权杖突然光芒万丈，嗡嗡作响，一道闪光向"
           +victim->query("c_name")+"射去\n\n" );
     tell_object( victim,
       "\n"+owner->query("c_name") 
           + "权杖突然嗡嗡作响并发出一道闪光，向你袭来!\n\n" );
     tell_room( environment(owner),
       "\n" +owner->query("c_name") 
           + "的权杖突然嗡嗡作响并发出一道闪光向" + victim->query("c_name") 
           + "射去!\n\n", ({ victim, owner }) );
     victim->receive_special_damage( "energy", inte );
     return inte;
   }
}
