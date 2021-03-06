#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "zombie captain", "僵尸船长" );
	add( "id", ({ "zombie", "captain"}) );
   set_short( "僵尸船长" );
	set_long(
		"一具又丑又凶恶的僵尸。\n"
	);
	set( "gender", "male" );
	set( "alignment", -800 );
	set( "killer", 1 );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "tactic_func", "my_tactic" );
	set_c_verbs( ({"%s用他的僵直的爪子抓向%s", "%s张开嘴往%s咬去",
		"%s五指张开，猛然往%s插下" }) );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 10 );
	set( "hit_points", 900 );
	set( "max_hp", 900 );
	set_natural_weapon( 30, 13, 28 );
}

int my_tactic()
{
	object victim;
	int dam;

	if( !(victim= query_attacker()) || (random(20)>2) ) return 0;
    tell_room( environment(),
           "僵尸口中发出一些怪声，使你觉得一阵晕眩....好像力量被吸走了。\n",
		this_object() );
	dam = 30 + random(20);
	victim->receive_special_damage( "evil", dam );
	receive_healing( dam );
	return 1;
}

void die()
{
   object torch, ball;
	
   ball = new( "/d/noden/bluesand/item/ball" );
   torch = new( "/obj/torch" );
   if( random(3)>1 ) {
        ball->move( this_object() );
     }
   else {
		torch->move( this_object() );
   }
	::die();
}
