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
		tell_object( me,"��İ�ħ�����ܲ�����ʹ����ȼ���ħ��!\n");
		return 0;
	}
	
	if( target == "NONE" ) dest = me;
	else if( !(dest= present( target, environment(me) )) ) {
	    tell_object( me,"Ҫ��˭ʩչ�ⶾ����\n");
	    return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	write("�㿪ʼ���а�ħ���нⶾ��������....��\n");
	tell_room( environment(me),
		me->query("c_name") + "��ʼ��һ����͵�������������....��\n",
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
	  tell_object( caster,"�㷢�����Ŀ���Ѿ��뿪�����ˡ�\n");
	  return;
	}
	if( !(cond = (mixed *)dest->query("conditions/simple_poison")) ) {
		tell_object( dest,"һ����͵İ�ɫ��â�������㣬����ʲ��Ҳû�з�����\n");
		return;
	}
	if( caster == dest )
		power = level * 20 + (int)caster->query_stat("int");
	else
		power = level * 15 + (int)caster->query_stat("int");
	if( power - cond[1]*cond[2] > random(cond[1]*cond[2]) ) {
		tell_object( dest,"һ����͵İ�ɫ��â�������㣬�����еĶ�����ˣ�\n");
		caster->gain_experience(cond[1]*cond[2]);
		call_other( CONDITION_PREFIX+"simple_poison", "remove_effect", dest );
	} else {
		tell_object( dest,"һ����͵İ�ɫ��â�������㣬�����еĶ������ˣ�\n");
		cond[1]--;
		cond[2]--;
		dest->set("conditions/simple_poison", cond);
	}
	tell_room( environment(dest),
		"һ����͵İ�ɫ��â������"+dest->query("c_name")+"��Ȼ����ɢȥ��\n",
		dest );
}