#include <mudlib.h>
#include <daemons.h>
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;

string str1="黑暗精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n";
string str2="你见到黑暗精灵随著黑雾消散掉了。\n";
string str3="HIW";

void create()
{
	::create();
	set_level(15);
	set_name( "dark spirit", "黑暗精灵" );
	add( "id", ({ "spirit" }) );
	set_short( "黑暗精灵" );
	set_long(
		"一团黑色的精灵，你只能看见那两颗闪闪发亮的眼睛。\n"
	);
	set( "unit", "个" );
	set( "race", "elf" );
	set( "alignment",  800 );
	set( "max_hp", 5000 );
	set( "hit_points", 5000 );
        set( "invisible",1);
	set_skill( "dodge", 50 );
}

void add_effect(object me)
{
  int i ;

  me->set_temp("extra_ac/body",AC_EFFECT+(int)me->query_temp("extra_ac/body"));
  me->set_temp("extra_db/body",DB_EFFECT+(int)me->query_temp("extra_db/body"));
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")+WC_EFFECT);
  return;
}

void remove_effect(object me)
{
  int i;

  me->set_temp("extra_ac/body",(int)me->query_temp("extra_ac/body")-AC_EFFECT);
  me->set_temp("extra_db/body",(int)me->query_temp("extra_db/body")-DB_EFFECT);
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")-WC_EFFECT);
  return ;
}

void check_battle1(object me)
{
  if (!this_object())
    return;
  if (!me->query_attacker()) {
    remove_effect(me);
    END->bye_bye(me,this_object(),15,str1,str2,str3);
    return;
  }
  else
    call_out("check_battle1",1,me);
  return;
}

void check_battle2(object me)
{
  if (!this_object())
    return;
  if (random(me->query_skill("polemic"))<=15) {
    remove_effect(me);
    END->bye_bye(me,this_object(),15,str1,str2,str3);
    return;
  }
  else
    call_out("check_battle2",4,me);
  return;
}

int my_action(object me)
{
 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"黑暗精灵对你说：没问题...我马上来帮你增加战斗潜能!\n");
    tell_object(me,set_color("一团黑雾飘了过来，你耳边听到黑暗精灵对你说:让我用暗黑斗气来提升你的战斗力吧 ! 不知它向你施了什麽法术，你突然觉的自己的精力大增。\n","HIW",me));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，一团黑雾飘了过来，隐隐约约可以看到一只黑暗精灵正对"+me->query("c_name")+"不知道施什麽法术。\n","HIW",me),me);
        add_effect(me);
        call_out("check_battle1",1,me);
        call_out("check_battle2",15+random(15),me);
	return 1;
}

