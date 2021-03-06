// This is a spell object
// By Annihilator@Eastern.Stories
#include <stats.h>
#include <conditions.h>

int query_sp_cost(object caster, int level, string target) { return 10 + level * 10; }

int query_need_skill(int level) { return 15+5*level; }

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object me, dest;

    me = this_player();
	chinese_mode = can_read_chinese(me);
	
	if( (int)me->query_skill("white-magic") < query_need_skill(level) ) {
		tell_object( me,"你的白魔法技能不足以使用这等级的魔法!\n");
		return 0;
	}
	
	if( target == "NONE" ) dest = me;
	else if( !(dest= present( target, environment(me) )) ) {
	    tell_object( me,"要对谁施展解毒术？\n");
	    return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	write("你开始吟诵白魔法中解毒术的咒文....。\n");
	tell_room( environment(me),
		me->query("c_name") + "开始以一种柔和的声音吟诵咒文....。\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	mixed *cond;
	int power;

	caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster,"你发现你的目标已经离开这里了。\n");
	  return;
	}
	if( !(cond = (mixed *)dest->query("conditions/simple_poison")) ) {
		tell_object( dest,"一团柔和的白色光芒笼罩著你，但是什麽也没有发生。\n");
		return;
	}
	if( caster == dest )
		power = level * 20 + (int)caster->query_stat("int");
	else
		power = level * 15 + (int)caster->query_stat("int");
	if( power - cond[1]*cond[2] > random(cond[1]*cond[2]) ) {
		tell_object( dest,"一团柔和的白色光芒笼罩著你，你所中的毒解除了！\n");
		caster->gain_experience(cond[1]*cond[2]);
		call_other( CONDITION_PREFIX+"simple_poison", "remove_effect", dest );
	} else {
		tell_object( dest,"一团柔和的白色光芒笼罩著你，你所中的毒减轻了！\n");
		cond[1]--;
		cond[2]--;
		dest->set("conditions/simple_poison", cond);
	}
	tell_room( environment(dest),
		"一团柔和的白色光芒笼罩著"+dest->query("c_name")+"，然後逐渐散去。\n",
		dest );
}
