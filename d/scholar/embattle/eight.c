#define NEED_NEMBERS 8
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define EMBATTLE_FAIL_DAMAGE 30
#define EMBATTLE_FAIL_RATE 25
#define COST_SP 15
#define EMBATTLE_NAME "����������"

string *c_message=({
    "����������������������������ⲽ��\n",
    "������������ͬ��Э���ѵ��˼������\n",
    "�����˵��˵��������������й������˵�����\n",
    "б��ֱ����ͻȻ����ֱ�����˵�Ҫ��\n",
    "����ȫ����ťʹ�������ݰ�����ĵ��⽣Ӱ֮��",
    "����ͬ��Σ�գ��Ӷ����ϵ���������֮���ɲ���\n"
                  });

int check_members(object *usr3,object me)
{
        int i,members = 0;

        for( i=0; i<sizeof(usr3); i++ ) 
           if (environment(usr3[i]) == environment(me))
		members ++ ;

        if ( members == NEED_NEMBERS ) return 1;
                else return 0;
}

void party_kill_ob(object *usr3,object victim)
{
        int i ;

        for( i=0; i<sizeof(usr3); i++ )
          if (environment(victim)==environment(usr3[i]))
		usr3[i]->kill_ob(victim);
	return;
}

void setup_effect(object *usr3,int total_int,string why)
{
        int i ;

        for( i=0; i<sizeof(usr3); i++ ) {
		usr3[i]->set_temp("embattle_busy",1);
		usr3[i]->set_temp("extra_ac/body",(total_int)/8+(int)usr3[i]->query_temp("extra_ac/body"));
                usr3[i]->set_temp("extra_db/body",(total_int/12)+(int)usr3[i]->query_temp("extra_db/body"));
	//	usr3[i]->calc_armor_class();
		usr3[i]->set_temp("extra_wc",(int)usr3[i]->query_temp("extra_wc")+(total_int/12));
                usr3[i]->set_temp("embattle_ac",total_int/8);
                usr3[i]->set_temp("embattle_db",total_int/12);
                usr3[i]->set_temp("embattle_wc",total_int/12);
                tell_object(usr3[i],why);
	}
	return;
}

void remove_effect(object *usr3,int total_int,string why)
{
        int i;

	why = set_color(why,"HIR");
        for( i=0; i<sizeof(usr3); i++ ) {
           if (usr3[i]->query_temp("embattle_busy")) {
		usr3[i]->delete_temp("embattle_busy"); 
        //        tell_object(usr3[i],"remove embattle_busy ok\n");
             	usr3[i]->set_temp("extra_ac/body",(int)usr3[i]->query_temp("extra_ac/body")-(total_int/8));
         //       tell_object(usr3[i],sprintf("remove ac %d\n",total_int));
                usr3[i]->set_temp("extra_db/body",(int)usr3[i]->query_temp("extra_db/body")-(total_int/12));
          //      tell_object(usr3[i],sprintf("remove db %d\n",total_int));
        //	usr3[i]->calc_armor_class();
		usr3[i]->set_temp("extra_wc",(int)usr3[i]->query_temp("extra_wc")-(total_int/12));
       //         tell_object(usr3[i],sprintf("remove wc %d\n",total_int));
		tell_object(usr3[i],why);
           }
	}
	return ;
}

void embattle_fail(object *usr3)
{
        int i;
	object victim;

        for( i=0; i<sizeof(usr3); i++ ) 
	  if (victim=usr3[i]->query_attacker()) {
		usr3[i]->receive_damage(EMBATTLE_FAIL_DAMAGE);
                tell_object(usr3[i],set_color(victim->query("c_name")+"ͻȻ���һ���������������..\n(��"+
		"/adm/daemons/statsd"->status_string(usr3[i])+")\n","HIY"));
	  }
	return;
}

int is_embattle_fail(object me)
{
	object victim;
	int rate ;

	victim = me->query_attacker();
	rate = (int)me->query_perm_stat("int")+(int)me->query_perm_stat("dex")
		+(int)me->query_perm_stat("kar");
	rate = rate+rate+rate-(int)victim->query_perm_stat("int")
			-(int)victim->query_perm_stat("dex");
	if (random(rate) > EMBATTLE_FAIL_RATE ) return 0;
	return 1;
}

void check_embattle(object me,object *usr3,object victim,int total_int)
{
        int is_special,flag;

	me->add("spell_points",-COST_SP);
	if ( !check_members(usr3,me)) {
		remove_effect(usr3,total_int,"������������ȷ������ɢ����..\n");
		return;
	}
        else if ( ! me->query_attacker()) {
                remove_effect(usr3,total_int,"ս��������������..\n");
                return ;
	}
	else if ( is_embattle_fail(me) ) {
		remove_effect(usr3,total_int,"�����ƺ������������ת����������������β��� ..\n");
		call_out("embattle_fail",3,usr3);
		return ;
	}
	else if ( (int)me->query("spell_points") < COST_SP ) {
                remove_effect(usr3,total_int,me->query("c_name")+"���񲻼��ˣ���û�а취��ά����ȥ��..\n");
                return ;
	}
        else if ( member_array(victim,me->query_attackers(),flag)==-1 ) {
                remove_effect(usr3,total_int,"ս��������������..\n");
                return ;
        }
	else {
                is_special=random(sizeof(c_message));
                if (is_special==3)
                   victim->receive_damage(-COST_SP);
                tell_room(environment(me),set_color(me->query("c_name")+c_message[is_special],"HIY",me));
                call_out("check_embattle",5,me,usr3,victim,total_int);
        }

	return;
}

int start_embattle(object me,object victim)
{
        int i,total_int=0;
        object *usr1,*usr2,*usr3=({}),other_leader;

        usr1 = (mixed *)me->query_temp("party_members");
        other_leader =  (object) me->query_temp("other_party_leader");
        usr2 = (mixed *)other_leader->query_temp("party_members");

        me->set_temp("effect_usr", ({}) );
        for( i=0; i<sizeof(usr1); i++ ) {
          usr3+=({usr1[i]});
          total_int+=(int)usr1[i]->query_stat("int");
        }
        for( i=0; i<sizeof(usr2); i++ ) {
          usr3+=({usr2[i]});
          total_int+=(int)usr2[i]->query_stat("int");
        }
        me->set_temp("effect_usr",usr3);

	if ( !check_members(usr3,me)) {
	  write("��� !! �������ԣ����ܽ����ȷ������ !!\n");
	  return 1;
	}

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
 	  return 1;
	}
        setup_effect(usr3,total_int,me->query("c_name")+"�󺰣����ע�� !! Ŀ��"+victim->query("c_name")+"��"+EMBATTLE_NAME+" -- ���� !!\n");
        me->set_temp("embattle_victim",victim);
        me->set_temp("embattle_party",(mixed *)me->query_temp("effect_usr"));
        me->set_temp("embattle_busy_check","eight");
         tell_room(environment(me),set_color(me->query("c_name")+"�Ķ���ͻȻ���һ�����Σ�Χס"+victim->query("c_name")+"����������\n","HIY"),usr3);
        party_kill_ob(usr3,victim);
	call_out("check_embattle",10,me,usr3,victim,total_int);
        return 1;
}