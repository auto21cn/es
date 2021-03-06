#include "../dony.h"
#include <daemons.h>
inherit MONSTER;
void create ()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "God longsword","陷仙剑[发狂状态]" );
	add ("id", ({ "god","longsword" }) );
	set_short( set_color("陷仙剑[发狂状态]","HIR") );
	set_long( @LONG
陷仙剑乃为通天教主所摆设诛仙阵里的四口宝剑之一。此剑倒悬门上, 发雷□动,
剑光一晃,任从他是万劫神仙,也难逃得此难。 昔曾有赞,赞此宝剑:「非铜非铁又
非钢,曾在须弥山下藏。 不用阴阳颠倒炼,岂无水火淬锋芒? 诛仙利,戮仙亡,陷仙
到处起红光;绝仙变化无穷妙,大罗神仙血染裳。」
LONG
	);
        set( "race", "undead" );
	set( "class", "knight" );
	set( "alignment", -3000 );
        set( "unit", "把" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 20 );
	set("max_hp", 1200);
	set("hit_points", 1200);
        set_temp("be_joke",10);
	set("persuing", 1);
        set("unbleeding",1);
        set("couple",1);
	set("aim_difficulty", ([ "critical" : 30, ]) );
	set("stun_difficulty",50);                                              
	set_natural_weapon( 40, 29, 33 );
	set_natural_armor( 110, 20 );
        set ("weight", 150);
        set ("special_defense", 
           ([ "all":70, "none" : 70 ]) );
        set_skill("dodge",85);
        set_skill("defend",100);
        set_c_verbs( ({ 
              "%s正在左冲右突彷佛如入无人之境,%s似乎被扫到",
              "%s划一个圈圈然後笔直飞起鹜地往%s疾冲了过去,剑峰凌厉己极",
              "%s鸣鸣作响一道长芒直削%s"}) );
        set_c_limbs( ({ "剑身", "把手", "剑背", }) );
        set( "tactic_func", "my_tactic" );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
         return 0;
}
int my_tactic()
{
   object *couples,victim;
   int i;
   if (!victim= query_attacker()) return 0;

   couples = filter_array( all_inventory(environment(this_object())),
       "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) 
        couples[i]->kill_ob(victim);
   if ( victim->query("npc") ) {
        tell_room( environment(this_object()),
        this_object()->query("c_name")+"把"+victim->query("c_name")+
          "吞入腹中....\n");
        this_object()->receive_healing(500);
        victim->remove();
   }
   return 0;
}
void die()
{
    object *all,obj;
    obj=this_object()->query("master");
    all=obj->query_temp("party_members");
    all=all-({ this_object() });
    obj->set_temp("party_members",all);
    delete_embattle_effect(this_object());
    set("alt_corpse",DWEAPON"kill1"); 
    set( "c_death_msg","%s被打落而成为一把普通的武器....\n\n");
    ::die();
}