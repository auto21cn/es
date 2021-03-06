#define LEVEL 15
#define NEED_SKILLS 75
#define COST_SP 30

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辩术技能不够驱使月光精灵来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使月光精灵来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤月光精灵来帮助你。\n","HIY"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic"))<=LEVEL)
    write("你和月光精灵之间的心灵传递没有成功\，召唤失败。\n");
  else {
    write("月光精灵对你说：没问题...我马上来帮你医疗!\n");
    tell_object(me,set_color("你见到一道黄光从天空直射而至，月光精灵从中走了出来，突然月光精灵全身放出一片\n金色光芒笼罩著你，你感觉一阵温暖，月光精灵又消失在黄光之中。\n","HIY"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，突然一道黄光从天空中直射而至，一只\n月光精灵从中走了出来，你见到月光精灵突然全身放出一片金色光芒笼罩"+me->query("c_name")+"之後，\n又消失在黄光之中。\n","HIY"),me);
    me->set_temp("summon_rest",1);
    me->receive_healing(LEVEL+random(LEVEL));
    call_out("can_summon_again",5+random(LEVEL),me);    
  }
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
