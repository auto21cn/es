#include "../saulin_temple.h"

#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("baby mushroom", "灵芝宝宝");
	add("id",({ "baby", "mushroom" }));
	set_short("灵芝宝宝" );
	set_long(
@DESC
一只正在啃著回阳草叶的灵芝宝宝，它正用好奇的眼光看著你。原来
这里住了一个灵芝家族，它们把水都引走了，难怪这口井会没水，你
想你可以向天心大师报告(report)有关发现灵芝(mushroom)家族的事。
DESC
	);
	set("unit", "只" );
	set("alignment", 250 );
	set_perm_stat("dex",10);
	set_perm_stat("str",6);
	set_perm_stat("kar",8);
	set("max_hp", 150);
	set("hit_points", 150);
	set("max_fp", 100);
	set("force_points", 100);	
	set_natural_weapon( 7, 4, 6 );
	set_natural_armor( 18, 10 );
	set("special_defense", ([ "all" : 20, ]) );
	set("unbleeding", 1);
	set("tactic_func", "sleepy" );
	set("exp_reward", 200 );
	set("alt_corpse", SAULIN_OBJ"small_pill" );
	set_c_verbs(({ "%s用身体撞%s", "%s用头撞%s" }));
	set_c_limbs(({ "身体", "头部" }));
	set("chat_chance",10);
	set("chat_output",({
        "灵芝宝宝眨著可爱的大眼睛说道：你是大野狼吗？ \n",
        "灵芝宝宝眨著可爱的大眼睛说道：你是叔叔还是阿姨？\n"
    }));
    set("c_death_msg","%s突然毫无生气地躺在地上... 不动了。\n");
}

int sleepy()
{
	object victim, mother;
	if( !(victim = query_attacker()) ) return 0;
	if( (mother = present("mami", environment())) &&
		((object)mother->query_attacker() != victim) ) {
		tell_object( victim, @ANGRY
		
站在你的身後的灵芝妈妈突然张牙舞爪的向你扑来，一面
大骂道：谁在欺负我的小孩，不想活了! 受死吧!!
	
ANGRY
 		);
 		mother->kill_ob(victim);
	}	
	if( random(20)>5 ) return 0;
    if( victim->query("stop_attack") ) return 0;
    tell_object( victim,
    	"灵芝宝宝散发出一种香气，你感到昏昏欲睡!!\n");

    tell_room( environment(), 
    	"灵芝宝宝，把"+victim->query("c_name")+"迷的不醒人事 !!\n"
		, ({ victim, this_object() })
	);
    victim->block_attack(4);
    victim->set_temp("msg_stop_attack", 
    	"( 你现在全身无力，只想好好的睡一觉 ! )\n" 
    );
    return 1;
}

void die()
{
    object killer, mother;

	::die();
    killer = query("last_attacker");
	if( (int)killer->query_level() >= 5 ) {
    	tell_room( environment(this_object()), 
    		@C_DIE_MESSAGE
    		
你正把灵芝宝宝解决掉，突然一阵怒骂声从你背後传来，你转头一看
突然又出现一只灵芝妈妈从你的身後张牙舞爪的向你扑来，一面大骂
道：你这麽高等级了还在欺负小孩，来尝尝我的厉害吧!!

C_DIE_MESSAGE
			,this_object()
		);
        if( !( mother=present("mami", environment()) ) ) {
        	mother = new( SAULIN_MONSTER"big_bug" );
        	mother->move( environment(killer) );
		}        
        mother->kill_ob(killer);
	}
}
