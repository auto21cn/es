#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("ant soldier", "战士蚁");
	add( "id", ({ "ant" }) );
	set_short("A ant solider", "战士蚁");
	set_long(
        "An exprienced ant fighter calls ant soldier .\n",
		"战士蚁是比兵蚁具战力的巨蚁，看起来就比兵蚁雄壮威武。\n"
	);
	set( "max_hp",180);
	set( "hit_points",180);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 170 );
	set_natural_weapon( 20, 8, 17 );
	set_natural_armor( 38, 15 );
	set_perm_stat("str",18);
	set_perm_stat("dex",15);
	set_perm_stat("con",17);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一声，抖了几下不动了 ....\n" );
	set_c_limbs( ({ "头部", "身体", "脚" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "tactic_func", "call_help");
	set("alt_corpse", MOYADA"obj/ant_corpse1" );
}

int is_a_ant(object obj)
{
   if( (string)obj->query("race")=="insect" ) return 1;
   return 0;
}

int call_help()
{
    object victim, env, obj, *ants;
    int i;
    victim = query_attacker();
    env = environment( this_object() );
    
    if( !victim ) return 0;
    ants = filter_array( all_inventory( env ), "is_a_ant", this_object() );
    i = sizeof( ants );
    while( i-- )
      if( !ants[i]->query_attackers() )
        ants[i]->kill_ob(victim);
    return 0;
}
