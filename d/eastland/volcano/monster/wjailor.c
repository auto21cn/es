#include "../oldcat.h" 

inherit MONSTER;

void create()
{
	object ob1,ob2;

	::create();
	set_level(14);
	set_name( "guard", "矮灵族守卫" );
	add( "id", ({ "guard" }) );
	set_short( "矮灵族守卫" );
	set_long(
	  "一个负则看守祭品的守卫，有他在这儿，想劫狱，再等一百年吧。\n"
	);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 20 );
	set_skill( "chain", 80 );
	set_skill( "parry", 80 );
	set_skill( "dodge", 60 );
        set_skill( "tactic", 80 );
	
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -800 );
        set( "tactic", "melee" );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 29 );
        set_natural_weapon(2,5,8);
	set( "wealth/gold", 20 );

	ob1=new(OWEAPON"wstar");
	ob1->move( this_object() );
	wield_weapon(ob1);

        ob2=new(OOBJ"wguard_key");
        ob2->move(this_object());

        equip_armor(OARMOR"mail4");
}

void die()
{
  object ob1,killer;

  killer=query("last_attacker");
  if (!killer) {
    ::die();
    return;
  }
  tell_object(killer,
    "守卫说：你终於还是技高一筹，不过你给我记住，我要和你再比一场，场地在阴间。\n");

  ::die();
}
