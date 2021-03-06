#define LEVEL 17
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define WEAPON_CLASS1 15
#define WEAPON_CLASS2 10
#define COST_SP 34

void add_effect(object me)
{
  int i ;

  me->set_temp("extra_ac/body",AC_EFFECT+(int)me->query_temp("extra_ac/body"));
  me->set_temp("extra_db/body",DB_EFFECT+(int)me->query_temp("extra_db/body"));
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")+WC_EFFECT);
  me->set("weapon_class1",(int)me->query("weapon_class1")+WEAPON_CLASS1);
  me->set("weapon_class2",(int)me->query("weapon_class2")+WEAPON_CLASS2);
  return;
}

void remove_effect(object me)
{
  int i;

  me->set_temp("extra_ac/body",(int)me->query_temp("extra_ac/body")-AC_EFFECT);
  me->set_temp("extra_db/body",(int)me->query_temp("extra_db/body")-DB_EFFECT);
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")-WC_EFFECT);
  me->set("weapon_class1",(int)me->query("weapon_class1")-WEAPON_CLASS1);
  me->set("weapon_class2",(int)me->query("weapon_class2")-WEAPON_CLASS2);
  return ;
}

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辩术技能不够驱使黑暗精灵来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使黑暗精灵来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤黑暗精灵来帮助你。\n","HIW"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和黑暗精灵之间的心灵传递没有成功\，召唤失败。\n");
  else {
    write("黑暗精灵对你说：没问题...我马上来帮你增加战斗潜能!\n");
    tell_object(me,set_color("一团黑雾飘了过来，你耳边听到黑暗精灵对你说:让我用暗黑斗气来提升你的战斗力吧 ! 不知它向你施了什麽法术，你突然觉的自己的精力大增。\n","HIW"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，一团黑雾飘了过来，隐隐约约可以看到一只黑暗精灵正对"+me->query("c_name")+"不知道施什麽法术。\n","HIW"),me);
    add_effect(me);
    me->set_temp("summon_rest",1);
    call_out("check_battle",LEVEL+random(LEVEL),me,mob);
  }
  return;
}

void check_battle(object me,object mob)
{
  if (!me->query_attacker()) {
    write("黑暗精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n"); 
    tell_room(environment(me),set_color("你见到黑暗精灵随著黑雾消散掉了。\n","HIW"));
    remove_effect(me);
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    write("黑暗精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n");
    tell_room(environment(me),set_color("你见到黑暗精灵随著黑雾消散掉了。\n","HIW"));
    remove_effect(me);
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
