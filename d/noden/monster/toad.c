// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("poisonus toad", "毒蟾蜍");
	add( "id", ({ "toad" }) );
   set_short("毒蟾蜍");
	set_long(
		"你看到一只巨大的蟾蜍，背上长著鲜红色的大斑点。\n"
	);
   set( "race", "amphibia" );
	set( "unit", "只" );
   set( "exp_reward", 933 );
	set( "alignment", -600 );
   set_natural_armor( 15, 6 );
   set( "max_hp", 300 );
   set( "hit_points", 300 );
	set_perm_stat( "int", 2 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 8 );
	set( "aggressive", 1 );
	set( "forgetful", 1 );
	set( "time_to_heal", 5 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "头部", "身体", "前脚", "後脚" }) );
	set_c_verbs( ({ "%s伸出痰绿色的舌头，挥向%s" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
            "毒蟾蜍从嘴巴喷出一股黑色的气体，刚好喷在你的面前 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 8, 8 );
	return 1;
}
