#include <mudlib.h>

inherit "/std/teacher";
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "mummy", "木乃伊" );
   set_short( "木乃伊" );
	set_long(
		"你看到一个全身绑著绷带的家伙，不过他看起来精神健旺，不像是受伤\n"
		"的样子，因为他正张开双手，想掐你的脖子！"
	);
   set( "race", "undead" );
	set_perm_stat( "str", 20 );
	set( "max_hp", 200 );
	set( "hit_points", 200 );
	set( "natural_defense_bonus", 18 );
	set( "natural_weapon_class1", 17 );
	set( "natural_min_damage1", 9 );
	set( "natural_max_damage1", 24 );
	set( "alignment", -1000 );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "tactic_func", "my_tactic" );
	set( "wealth/gold", 30 );

	set( "unit", "只" );
	set_c_verbs( ({ "%s五指伸缩不定，抓向%s", "%s发出「哦」的一声，手臂突然变长，往%s抓去",
		"%s握紧拳头，硬梆梆地对著%s挥出一拳" }) );
	set_lessons( ([
           "bandage": ({ 100, 60 })
	]) );
   set( "alt_corpse", "/d/noden/tomb/obj/mummy" );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<13 || !(victim = query_attackers()) ) return 0;
    tell_room( environment(),
            "木乃伊口中咿呀怪叫，使你感到一股无法抗拒的恐怖！\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->run_away();
	return 1;
}

int check_trainee(object trainee)
{
   if( !present("spider ankh", trainee) )
   return notify_fail(
         "请先找到信物！\n" );
	if( (string)trainee->query("class")=="adventurer" 
	&& (int)trainee->query_level() > 4 )
		return 1;
	else
             return notify_fail( 
                    "木乃伊说道: 我只教够资格的冒险者，你的条件不合！\n" );
}

void init()
{
   teacher::init();
   npc::init();
}
