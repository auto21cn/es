// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("hornet", "黄蜂");
   set_short("黄蜂");
	set_long(
		"你看到一只嗡嗡叫的黄蜂，最好在你被它盯上之前赶快溜吧。\n"
	);
   set( "race", "insect" );
	set( "unit", "只" );
   set( "exp_reward", 156 );
	set( "tactic_func", "sting" );
	set( "killer", 1 );
	set( "pursuing", 1 );
	set( "moving", 1 );
	set( "speed", 15 );
	set( "natural_weapon_class1", 5 );
	set( "c_death_msg", "%s无力地落到地上，死翘翘了 ....\n" );
	set_c_limbs( ({ "头部", "身体", "翅膀" }) );
	set_c_verbs( ({ "%s发出嗡嗡的叫声，往%s叮去" }) );
	setenv( "C_MIN", "一只$N飞了过来。" );
	setenv( "C_MOUT", "$N往$D边飞走。" );
}

int sting()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_object( victim,
            "黄蜂飞到你的脸上，你感到脸上一阵刺痛！\n" );
    tell_room( environment(this_object()),
            "黄蜂飞到" + victim->query("c_name") + "的脸上，用尾针往下一螫！\n",
                ({this_object(),victim}) );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 3 );
	return 1;
}
