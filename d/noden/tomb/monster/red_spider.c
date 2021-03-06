#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "red spider", "红蜘蛛" );
	add( "id", ({ "spider" }) );
   set_short( "红蜘蛛" );
	set_long(
		"你看到一只体型硕大的红蜘蛛，这种蜘蛛并不会结网，它们是专靠快速的行动\n"
		"与强有力的肢体捕食小动物，这只蜘蛛的体型颇大，它看起来好像饿了。\n"
	);
   set("race","insect");
	set_perm_stat( "dex", 7 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 9 );
	set( "alignment", -600 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "my_tactic" );

	set( "unit", "只" );
	set_c_verbs( ({ "%s张著两只大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺",
		"%s用身上尖锐的硬毛往%s螫去" }) );
	set_c_limbs( ({ "头部", "身体", "腿部" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<15 || !(victim = query_attackers()) ) return 0;
    tell_room( environment(),
            "红蜘蛛口中喷出一股红色的气体，使你觉得手脚发软，昏昏欲睡！\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "poison", 16 );
	return 1;
}
