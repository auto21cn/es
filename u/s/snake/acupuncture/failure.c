// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

int query_sp_cost(int eff_lv,int skill_lv)
{
    return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_skill() { return 0 ; }


int acu_effect(int level, object target)
{
	int delay_time;
	object me ;

        me = this_player();
	
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
	
	write(  "你随地坐下并牵起"+target->query("c_name")+
		"的手,缓缓将气送出去。\n" );
	tell_room( environment(me), 
		me->query("c_name") + "随地坐下并牵起"
		+target->query("c_name")+"的手,缓缓将气送出去。\n",
		({ me ,target}) );
        tell_object(target,me->query("c_name") + 
                           "随地坐下并牵起你的手,缓缓将气送进来。\n" ) ;

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	if( !dest || !present(dest, environment(caster)) ) 
	{
	  tell_object( caster, 
	    "不知怎麽的,也许是觉得你是个蒙古大夫。总之,你的患者走掉了。\n");
	  return;
	}
	
	tell_object( dest,
	    "你觉得体内的血气开始快速流动，但是你全身突然开始剧痛....。\n");
	tell_room( environment(dest), 
	        dest->query("c_name")+"的脸开始发红, 红得像是要渗出血来了。\n"
		,dest );
	tell_object( caster,
	    "你突然发现对方血气向你激汤过来,当你想收手已经来不及....。\n");
	dest->receive_damage( level * 5 );        
	caster->receive_damage( level * 5 );        
        return ;
}



