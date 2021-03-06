#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "huge spider", "巨蜘蛛" );
	add( "id", ({ "spider" }) );
   set_short( "巨蜘蛛" );
	set_long(
		"你看到一只体型硕大的蜘蛛，这种蜘蛛并不会结网，它们是专靠快速的行动\n"
		"与强有力的肢体捕食小动物，这只蜘蛛的体型颇大，它看起来好像饿了。\n"
	);
   set("race","insect");
	set_perm_stat( "dex", 5 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 6 );
	set( "alignment", -300 );
	set( "aggressive", 1 );
	set( "tactic_func", "my_tactic" );

	set( "unit", "只" );
	set_c_verbs( ({ "%s张著两只大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺" }) );
	set_c_limbs( ({ "头部", "身体", "腿部" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<15 || !(victim = query_attackers()) ) return 0;
   tell_room( environment(),
             "巨蜘蛛口中喷出一股黄色的气体，使你觉得头晕脑胀，想要呕吐！\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "poison", 10 );
	return 1;
}
