#include "../../story.h"
inherit WMOB"helpmob" ;
void create ()
{
	::create();
	set_level(17);
	set_name( "general", "众天神将" );
	add ("id", ({"general"}) );
	set_short( "众天神将");
	set_long(@CLONG
这是领导诸天兵奋力抵抗蚩尤大军的天神，他正聚精会神地看守自己的岗位。
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 30 );
        set_perm_stat("int", 23 );
	set( "alignment", 100 );
        set( "max_fp",200);
        set( "max_hp",900);
        set( "hit_points",900);
	set_natural_weapon( 10, 3, 7 );
	set_natural_armor( 37, 15 );
        set("wealth/gold",50);
        set_skill("dodge",85);
        set_skill("parry",85);
        set_skill("shortblade",70);
        set("couple",1);
        wield_weapon(SPWEA"sword2");
        equip_armor(SPARM"soldier_shield1");
        equip_armor(SPARM"soldier_plate2");
        set("special_defense",(["all":30,"none":25]));
        set( "tactic_func", "my_attack" );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
               
int my_attack()
{
    object *couple,victim;
    int i,max;
                     
    if ( !victim = query_attacker() ) return 0;
    couple = filter_array( all_inventory(environment(this_object())),
         "can_help", this_object() );
    max=sizeof(couple);
    for( i=0; i<max; i++ ) 
       couple[i]->kill_ob(victim);
    return 0;
}