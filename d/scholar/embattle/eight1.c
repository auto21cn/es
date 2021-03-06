#define NEED_NEMBERS 4
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define EMBATTLE_FAIL_DAMAGE 30
#define EMBATTLE_FAIL_RATE 25
#define COST_SP 10
#define EMBATTLE_NAME "八卦游龙阵"

int total_int=0,flag=1;

string *c_message=({
    "带领著队伍走著八卦游龙阵的特殊步法\n",
    "喊著：让我们同心协力把敌人歼灭掉吧\n",
    "发现了敌人的破绽，连出三招攻击敌人的破绽\n",
    "斜退直进，突然出招直击敌人的要害\n",
    "控制全阵枢钮使敌人身陷八卦阵的刀光剑影之中",
    "发现同伴危险，挥动手上的武器攻敌之不可不守\n"
                  });

int check_members(object *usr)
{
        int i,members = 0 ;

        for( i=0; i<sizeof(usr); i++ ) 
                if (environment(usr[i]) == environment(this_player())) {
                   if(flag) total_int+=(int)usr[i]->query_stat("int");
			members ++ ;
		}

        if ( members == NEED_NEMBERS ) return 1;
                else return 0;
}

void party_kill_ob(object *usr,object victim)
{
        int i ;

        for( i=0; i<sizeof(usr); i++ )
          if (environment(victim)==environment(usr[i]))
		usr[i]->kill_ob(victim);
	return;
}

void setup_effect(object *usr,string why)
{
        int i ;

        for( i=0; i<sizeof(usr); i++ ) {
		usr[i]->set_temp("embattle_busy",1);
		usr[i]->set_temp("extra_ac/body",(total_int)/4+(int)usr[i]->query_temp("extra_ac/body"));
                usr[i]->set_temp("extra_db/body",(total_int/6)+(int)usr[i]->query_temp("extra_db/body"));
		usr[i]->calc_armor_class();
		usr[i]->set_temp("extra_wc",(int)usr[i]->query_temp("extra_wc")+(total_int/6));
                usr[i]->set_temp("embattle_ac",total_int/4);
                usr[i]->set_temp("embattle_db",total_int/6);
                usr[i]->set_temp("embattle_wc",total_int/6);
//  这是多馀的工作，extra_wc 会重改 weapon_class1 ，而设定 weapon class2 会
//	造成不存在的双手武器，都应去除。
//  我不了解增加这两个的原因，请再 check 一下
//  关於战斗的详细情形请参考 /std/body/attack.c
                tell_object(usr[i],why);
	}
	return;
}

void remove_effect(object *usr,string why)
{
        int i;

	why = set_color(why,"HIR");
        for( i=0; i<sizeof(usr); i++ ) {
		usr[i]->delete_temp("embattle_busy");
		usr[i]->set_temp("extra_ac/body",(int)usr[i]->query_temp("extra_ac/body")-(total_int/4));
                usr[i]->set_temp("extra_db/body",(int)usr[i]->query_temp("extra_db/body")-(total_int/6));
		usr[i]->calc_armor_class();
		usr[i]->set_temp("extra_wc",(int)usr[i]->query_temp("extra_wc")-(total_int/6));
		tell_object(usr[i],why);
		}
	return ;
}

void embattle_fail(object *usr)
{
        int i;
	object victim;

        for( i=0; i<sizeof(usr); i++ ) 
	if (victim=usr[i]->query_attacker()) {
		usr[i]->receive_damage(EMBATTLE_FAIL_DAMAGE);
                tell_object(usr[i],set_color(victim->query("c_name")+"突然大吼一声，攻向你的破绽..\n(你"+
		"/adm/daemons/statsd"->status_string(usr[i])+")\n","HIY"));
	}
	return;
}

int is_embattle_fail()
{
	object me,victim;
	int rate ;

	me = this_player();
	victim = me->query_attacker();
	rate = (int)me->query_perm_stat("int")+(int)me->query_perm_stat("dex")
		+(int)me->query_perm_stat("kar");
	rate = rate+rate+rate-(int)victim->query_perm_stat("int")
			-(int)victim->query_perm_stat("dex");
	if (random(rate) > EMBATTLE_FAIL_RATE ) return 0;
	return 1;
}

void check_embattle(object *usr,object place,object victim)
{
        int is_special,flag;

	this_player()->add("spell_points",-COST_SP);
	if ( !check_members(usr)) {
		remove_effect(usr,"阵中人数不正确，阵形散乱了..\n");
                place->set("eight_zeng_ok",0);
		return;
	}
        else if ( ! this_player()->query_attacker()) {
                remove_effect(usr,"战斗结束，收阵了..\n");
                place->set("eight_zeng_ok",0);
                return ;
	}
	else if ( is_embattle_fail() ) {
		remove_effect(usr,"敌人似乎察觉了阵势运转的破绽，你觉得情形不对 ..\n");
                place->set("eight_zeng_ok",0);
		call_out("embattle_fail",3,usr);
		return ;
	}
	else if ( (int)this_player()->query("spell_points") < COST_SP ) {
                remove_effect(usr,this_player()->query("c_name")+"精神不济了，阵法没有办法再维持下去了..\n");
                place->set("eight_zeng_ok",0);
                return ;
	}
        else if (!(int)place->query("eight_zeng_ok")) {
                remove_effect(usr,"另一队伍发生问题，阵法运作失败..\n");
                return;
        }
        else if ( member_array(victim,this_player()->query_attackers(),flag)==-1 ) {
                remove_effect(usr,"战斗结束，收阵了..\n");
                return ;
        }
	else {
                is_special=random(sizeof(c_message));
                if (is_special==3)
                   victim->receive_damage(-COST_SP);
                tell_room(environment(this_player()),set_color(this_player()->query("c_name")+c_message[is_special],"HIY"));
                call_out("check_embattle",5,usr,place,victim);
        }

	return;
}

int start_embattle(object me,object victim)
{
        object *usr,place;

        usr = (mixed *)me->query_temp("party_members");
        place=environment(me);

	if ( !check_members(usr)) {
		write("糟糕 !! 人数不对，不能结成正确的阵势 !!\n");
                place->set("eight_zeng_ok",0);
                place->delete("eight/"+me->query("cap_name"));
		return 1;
	}

        flag=0;

	if ( (int)me->query("spell_points") < COST_SP ) {
		write("你的精神不济了，应该好好休息一下。\n");
                place->set("eight_zeng_ok",0);
                place->delete("eight/"+me->query("cap_name"));
		return 1;
	}
        call_out("check_party",1,me,victim,usr,place);
	call_out("check_embattle",5,usr,place,victim);
        return 1;
}

int check_party(object me,object victim,object *usr,object place)
{
  if (place->query("eight_zeng_ok")==0)
    write("另一个队伍有问题，结阵失败 !\n");
  else {
    setup_effect(usr,me->query("c_name")+"大喊：大家注意 !! 目标"+victim->query("c_name")+"，"+EMBATTLE_NAME+" -- 结阵 !!\n");
    me->set_temp("embattle_victim",victim);
    me->set_temp("embattle_party",me->query_temp("party_members"));
    me->set_temp("embattle_busy_check","eight");
    tell_room(environment(me),set_color(me->query("c_name")+"的队伍突然结成一个阵形，围住"+victim->query("c_name")+"发动攻击。\n","HIY"),usr);
    party_kill_ob(usr,victim);
  }
  me->delete_temp("embattle_ready_check");
  call_out("delete_mark",2,me,place);
  return 1;
}

int delete_mark(object me,object place)
{
  place->delete("eight/"+me->query("cap_name"));
  return 1;
}
