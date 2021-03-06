#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "zombie", "僵尸" );
   set_short( "僵尸" );
	set_long(
		"一具又丑又凶恶的僵尸。\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", -400 );
	set( "aggressive", 1 );
	set( "tactic_func", "my_tactic" );
	set_c_verbs( ({"%s用他的僵直的爪子抓向%s", "%s张开嘴往%s咬去",
		"%s五指张开，猛然往%s插下" }) );
}

int my_tactic()
{
	object victim;
	int dam;

	if( !(victim= query_attacker()) || (random(20)>2) ) return 0;
    tell_room( environment(),
            "僵尸口中发出一些怪声，使你觉得一阵晕眩....好像力量被吸走了。\n",
		this_object() );
	dam = 15 + random(10);
	victim->receive_special_damage( "evil", dam );
	receive_healing( dam );
	return 1;
}

