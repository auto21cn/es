#define LEVEL 8
#define AC_EFFECT 15
#define DB_EFFECT 8
#define WC_EFFECT 8
#define WEAPON_CLASS1 10
#define WEAPON_CLASS2 5
#define COST_SP 16

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
          write("你的辩术技能不够驱使木精灵来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的阴阳学技能不够驱使木精灵来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤木精灵来帮助你。\n","HIG"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和木精灵之间的心灵传递没有成功\，召唤失败。\n");
  else {
    me->set("demand/wood",2);
    write("木精灵对你说：没问题...我马上来帮你增加战斗潜能!\n");
    tell_object(me,set_color("平地中长出一棵树来，一只木精灵从树洞中跳了出来，木精灵说：让我用大自然的力量来提升你的战斗力吧 ! 不知它向你施了什麽法术，你突然觉的自己的精力大增。\n","HIG"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，平地中长出一棵树来，一只木精灵从树洞中跳了出来，对著"+me->query("c_name")+"不知道施什麽法术。\n","HIG"),me);
    add_effect(me);
    me->set_temp("summon_rest",1);
    call_out("check_battle",LEVEL+random(LEVEL),me,mob);
  }
  return;
}

void check_battle(object me,object mob)
{
  if (!me->query_attacker()) {
    write("木精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n"); 
    tell_room(environment(me),set_color("你见到木精灵跳回树洞，树又缩了回去。\n","HIG"));
    remove_effect(me);
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    write("木精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n");
    tell_room(environment(me),set_color("你见到木精灵跳回树洞，树又缩了回去。\n","HIG"));
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
