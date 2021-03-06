#define LEVEL 16
#define NEED_SKILLS 80
#define COST_SP 32
#define SCHOLAR_SUMMON_SPIRIT "/d/scholar/demand/spirit/"

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辩术技能不够驱使剑魂来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使剑魂来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤剑魂来帮助你。\n","HIW"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和剑魂之间的心灵传递没有成功\，召唤失败。\n");
  else {
    write("剑魂对你说：没问题...我马上来帮你击退敌人!\n");
    tell_object(me,set_color("你感觉到一道剑气直射而至，剑魂化成一把宝剑在空中飞舞著预备和你一起攻击敌人。\n","HIW"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，突然你感到一道剑气直射而至，剑魂化成一把宝剑在空中飞舞著，开始对"+me->query("c_name")+"的敌人发动攻击\n","HIW"),me);
    me->set_temp("summon_rest",1);
    seteuid(getuid());
    mob=new(SCHOLAR_SUMMON_SPIRIT"sword_spirit");
    mob->move(environment(me));    
    mob->set("master",me);
    mob->kill_ob(me->query_attacker());
    call_out("check_battle1",1,me,mob);
    call_out("check_battle2",random(LEVEL),me,mob);
  }
  return;
}

void check_battle1(object me,object mob)
{
  if (!mob)
    return;
  if (!me->query_attacker()) {
    tell_room(environment(mob),set_color("你看到剑魂化成一道剑气离你而去。\n","HIW"));
    tell_object(me,"剑魂说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n");
    mob->remove();
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else
    call_out("check_battle1",1,me,mob);
}

void check_battle2(object me,object mob)
{
  if (!mob)
    return;
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    tell_object(me,"剑魂说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n");
    tell_room(environment(mob),set_color("你看到剑魂化成一道剑气离你而去。\。\n","HIW"));
    mob->remove();
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else 
    call_out("check_battle",4,me,mob);
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
