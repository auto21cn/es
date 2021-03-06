// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("spectral crow", "鬼魅乌鸦");
	add( "id", ({ "crow" }) );
   set_short("鬼魅乌鸦");
	set_long(
		"你看到一只轮廓十分模糊的黑色乌鸦，一种不祥的预感告诉你这是种\n"
		"邪恶的化身。\n"
	);
	set( "unit", "只" );
	set( "alignment", -300 );
   set( "exp_reward", 320 );
   set( "max_hp", 220 );
   set( "hit_points", 220 );
   set_natural_armor( 15, 5 );
	set_natural_weapon( 7, 3, 8 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 5 );
	set( "aggressive", 1 );
	set( "tactic_func", "cry" );
	set_c_limbs( ({ "头部", "身体", "翅膀" }) );
	set_c_verbs( ({ "%s用嘴向%s用力一啄", "%s用爪子往%s抓去" }) );
}

int cry()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
  tell_room( environment(this_object()),
            "鬼魅乌鸦发出一阵凄厉的叫声，好像濒死生物的惨叫声 ....\n",
		this_object() );
	CONFUSED->apply_effect( victim, 10, 5 );
	return 1;
}
