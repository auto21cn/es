
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name("centipede", "蜈蚣");
   set_short("蜈蚣");
	set_long(
     "你看到一只黑色的蜈蚣, 一双深红的眼睛正盯著你,\n"
     "令你不禁倒抽一口凉气!\n"
	);
   set("race","insect");
   set( "unit", "条" );
   set( "alignment", -500 );
   set( "exp_reward", 1350 );
   set_natural_armor( 30, 15 );
   set_natural_weapon( 10, 5, 9 );
   set( "max_hp", 400 );
   set( "hit_points", 400 );
   set_perm_stat( "int", 5 );
   set( "killer", 1 );
	set( "tactic_func", "emit_poison" );
   set_c_limbs( ({ "头部", "身体", "足部" }) );
   set_c_verbs( ({ "%s的尾巴扫向%s", "%s的头部撞向%s" }) );
}

int emit_poison(object victim)
{

   if( random(20)>3 || !(victim= query_attacker()) ) return 0;
   if( random(20)<4 ) {
    tell_room( environment(this_object()),
     "\n蜈蚣突然附在你的身上, 狠狠地咬了你一口...\n",
		this_object() );
   (CONDITION_PREFIX + "weak")->apply_effect( victim, 10, 3 );
   }
	return 1;
}

