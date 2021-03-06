// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("snake", "毒蛇");
   set_short("毒蛇");
	set_long(
		"这条蛇的头是三角形的，你想起小时候从书上看到的，有三角形头部的蛇\n"
		"大部分是有毒的。\n"
	);
	set( "unit", "条" );
	set( "alignment", -300 );
   set_perm_stat( "dex", 8 );
    set( "max_hp", 300 );
    set( "hit_points", 300 );
   set_natural_armor( 30, 10 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 4 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "头部", "身体", "尾巴" }) );
	set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
   set( "exp_reward", 513 );
}

int emit_poison()
{
	object victim;

   if( random(20)>5 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
           "毒蛇从嘴巴喷出一股绿色的气体，刚好喷在你的面前 ....\n",
		this_object() );
   (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 10, 3 );
	return 1;
}
