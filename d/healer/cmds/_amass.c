// 气盾术
//
//		Lilia

////#pragma save_binary

#include <mudlib.h>

#define QUESTNAME "lost_kingdom"
#define SP_COST	50

int help();

int remove_block(object obj)
{
    obj->delete_temp("block_command");
    return 1;
}

int cmd_amass()
{
    int skill, delay_time;
    object me;

    me = this_player();
    if ((int)me->query(QUESTNAME) != 8) return 0;

    skill = me->query("dou-in");
    if (!skill)
	return notify_fail("你还没练过气功，没有办法聚气。\n");

    if ((int)me->query("stop_attack") > 0)
	return notify_fail("( 你上一个动作还没有完成，无法专心聚气。 )\n");

    if (!(!(me->query_current_attacker())))
	return notify_fail("你还在战斗中，没时间停下来聚气。\n");

    if (me->query_temp("no_concentrate"))
	return notify_fail("你的注意力还不能集中，无法聚气。\n");

    if (me->query("spell_points") < SP_COST)
	return notify_fail("你的真气不足，无法聚气。\n");

    if (me->query("npc"))
	delay_time = 0;
    else
	delay_time = 3;

    me->block_attack(delay_time);
    me->set_temp("msg_stop_attack", "( 你正在专心聚气，没办法做其他事! )\n");
    tell_object(me, "你闭目凝神，开始聚气 ...\n");
    tell_room(environment(me), me->query("c_name")+"闭目凝神，开始聚气 ...\n", me);
    call_out("effect", delay_time, me);
    return 1;
}

void effect(object me)
{
    int duration, sp;

    if (me->query_temp("effect/protect"))
	tell_object(me, "一阵微风轻轻地拂在你的脸上，令你觉得十分清爽 ...\n");
    else
	tell_object(me, "一阵旋风呼应著你体内真气的流动，围绕在你的四周形成了气盾保护著你!\n");

    tell_room(environment(me), "似乎有一阵风围绕在"+me->query("c_name")+"的四周 ... 该不会是错觉吧? ...\n", me);

    duration = me->query_stat("pie") * 3 + 50;
    me->set_temp("extra_db/protect", (int)me->query("dou-in"));
    me->set_temp("extra_ac/protect", 10);
    me->set_temp("effect/protect", 1);
    me->calc_armor_class();
    me->delete_temp("msg_stop_attack");
    sp = (int)me->query("spell_points");
    sp -= SP_COST;
    me->set("spell_points", sp);
    call_out("expire", duration, me);
}

void expire(object me)
{
    if (!me) return;

    tell_object(me, "你觉得四周的风势小了下来，气盾消失了 ...\n");

    me->delete_temp("extra_db/protect");
    me->delete_temp("extra_ac/protect");
    me->delete_temp("effect/protect");
    me->calc_armor_class();
}

