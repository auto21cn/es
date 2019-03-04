#include <mudlib.h>
#include <daemons.h>
#define COST_SP 4
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
int life_time=19;
string name;
       
string str1="大地精灵说：我的朋友、我必须要走了，假如须要我帮忙请再叫我。\n";
string str2="你见到地面裂了开来，大地精灵钻了进去。\n";
string str3="HIM";

void create()
{
	::create();
	set_level(19);
	set_name( "solid spirit", "大地精灵" );
	add( "id", ({ "spirit" }) );
	set_short( "大地精灵" );
	set_long(
		"一个灰黑色充满神力的精灵。\n"
	);
	set( "unit", "个" );
	set( "race", "elf" );
	set( "alignment",  800 );
        set( "tactic", "flank");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({"%s用脚往地上一蹬，地面一个隆起往%s撞去",
                       "%s用手向空中一挥，一阵风压向%s直逼过去",
                       "%s把自己的身体当作武器，向%s冲了过去"}) );
}

int environment_check()
{
  return 1;
}

/*
int receive_damage(int damage)
{
       int hits;
       object act_ob,master;

       master=(object)query_temp("master");
       hits = (int)master->query("hit_points");
       act_ob = previous_object();
       if( act_ob && living(act_ob) ) set("last_attacker", act_ob);
       if( damage <= 0 || link_data("dead") || hits < 1 || query("linkdead") )
                return 0;
       hits -= damage/2;
       master->set( "hit_points", hits );
       set("hit_points",hits);
       seteuid(getuid());
       tell_object(master," ( 你"+(string)"/adm/daemons/statsd"->c_status_string(master)+" )\n");
       return 1;
}
*/
int my_action(object me)
{
        int life;
        object victim;
        seteuid(getuid());
        me->set_temp("summon_rest",1);
        life = (int)me->query("spell_points")/COST_SP ;
        if (life < life_time )
                life_time = life ;
        this_object()->move(environment(me));
        tell_object(me,"大地精灵对你说：没问题...我马上来帮你击退敌人!\n");
    tell_object(me,set_color("你见到地面突然裂开，大地精灵从中冲了出来和你一起攻击敌人。\n","HIM"));
    tell_room(environment(me),set_color("你见到"+me->query("c_name")+"神情专注的念著一些咒语，突然从地面裂开，出现一个大地精灵\n对"+me->query("c_name")+"的敌人发动攻击。\n","HIM"),me);
    	victim = me->query_attacker();
        if (victim) {
          kill_ob(victim);
	  victim->remove_attacker(this_object());
        } 
        name=me->query("name");   
        call_out("check_battle",1,me,this_object());
        return 1;
}

/*
void wait_get_exp(object me,object mob)
{
  END->bye_bye(me,mob,19,str1,str2,str3);
  return;
}
*/

void check_battle(object me,object mob)
{
  object tmp;
  if (!mob)
    return;
  if (!(tmp=find_living(name))||(tmp->query("npc"))) {
    tell_room(environment(mob),
      "大地精灵在你的身後大叫：臭小子，居然给我QUIT掉了...\n"
      "说完也跟著消失了。\n");
    mob->remove();  
    return;
  }  
  else if (!me->query_attacker()) {
    // no need delay now. player
    //call_out("wait_get_exp",1,me,mob);
    END->bye_bye(me,mob,19,str1,str2,str3);
    return;
  }
  else if (!mob->query_attacker()) {
    END->bye_bye(me,mob,19,str1,str2,str3);
    return;
  }
  else if ( ! present(me,environment()) ) {
     END->bye_bye(me,mob,19,str1,str2,str3);
     return;
  }
  else
    call_out("check_battle",2,me,mob);
}

int my_tactic()
{
        object master,victim;
		int dam;

        master = (object)query_temp("master");
       if (!master) return 0;
        if ((int)master->query("spell_points")<0)
           return END->bye_bye(master,this_object(),19,str1,str2,str3);
        master->add("spell_points",-COST_SP);
        if ( life_time-- < 0 ) 
           return END->bye_bye(master,this_object(),19,str1,str2,str3);
/*        if ( ! present(master,environment()) ) {
          tell_object(master,"大地精灵在你的身後大叫：臭小子，丢下我烙跑？？你给我记志 ...\n");
          tell_room(environment(),"大地精灵叫道 : 哎啊 ! "+master->query("c_name")+"这个臭小子丢下我跑了？我也要溜了 ..\n");
          if ( !wizardp(master) )
            END->can_summon_again(master,19);
          else
            master->delete_temp("summon_rest");
          this_object()->init_attack();
          this_object()->remove();
          return 0;
        }
*/
	if( !(victim = query_attacker()) ) return 0;
	this_object()->execute_attack(0);
	if( random(20)<2 ) {
	  dam = 10 + 2*random(19);
//	if ( (int)victim->query("hit_points") < dam ) return 0;
          victim->set("stop_attack",2);
	  tell_room( environment(this_object()),
	    set_color("\n大地精灵用它那强壮有力的四肢向敌人施展它的必杀技：十字锁喉反扣!\n\n","HIR",master)
	    , this_object()
	  );
	  victim->receive_special_damage("energy", dam);
        }
        if (victim->query("last_attacker")==this_object())
          victim->set("last_attacker",master); 
 	// now execute_attack() called by tactic function.
 	return 1;
}

/*
int gain_experience(int exp)
{
        object master;
        if ( query_attacker() ) return 1;
        master = (object)this_object()->query_temp("master");
        if ( !present(master,environment()) )
                return END->bye_bye(master,this_object(),19,str1,str2,str3);
        if ( master->query_temp("leader") )
                PARTY_D->share_experience(master,exp ) ;
        else {
                        master->gain_experience(exp);
            tell_object(master,sprintf("你得到 %d 点经验值。\n",exp));
                        }
        return END->bye_bye(master,this_object(),19,str1,str2,str3);
}
*/
