#include "takeda.h"
#include <stats.h>
#include <conditions.h>

inherit WEAPON;

void create()
{
       set_name("thief's dagger","盗贼匕首");
       add("id",({"dagger"}) );
       set_short("盗贼匕首");
	   set_long(
           "这是一把盗贼常用的匕首，为便利作案，刀锋上还抹了些毒，\n"
	   "真是卑鄙的行为......\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 18 );
        set( "type","dagger");
	set( "second",1);
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "weight", 50 );
	set( "value", ({ 23, "gold" }) );
//        set( "hit_func","emit_poison");	
}
int emit_poison(object victim)
{
     object holder;
if ( !victim) return 0;
if (!(holder= environment(this_object())) || !living(holder) ) return 0;
if (random(8)>1) return 0;
   else {
victim->set("last_attacker",holder);

tell_room( environment(holder),
"\n"+holder->query("c_name")+"的匕首使敌人中毒．\n",
this_object());
(CONDITION_PREFIX + "simple_poison")->apply_effect(victim,8,5);
return 1;
       }
}
	
