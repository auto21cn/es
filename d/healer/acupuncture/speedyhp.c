// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// acupuncture by Indra@ES
#include <conditions.h>

#define EFFECT_ID "speedyhp"
#define BASIC_NEEDED 2

int query_sp_cost(int eff_lv,int skill_lv)
{
       return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_level() { return BASIC_NEEDED ; }

int acu_effect(int level, object target)
{
	int delay_time;
        string targetname ;
	object me ;

        me = this_player();
	
        delay_time = 3;
	me->block_attack(delay_time) ;
	me->set_temp("cast_busy", 1) ;
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
       
        if(target == me) targetname = "自己" ;
        else
        { 
          targetname = target->query("c_name") ;
          tell_object(target,sprintf(
                     "%s随地坐下并牵起你的手,缓缓将气送进来。\n",
                     me->query("c_name")
                     ) ) ;
         }

	write(sprintf("你席地坐下并牵起%s的手,缓缓将气送出去。\n",
	               targetname));

	tell_room( environment(me),sprintf( 
		"%s随地坐下并牵起%s的手,缓缓将气送出去。\n",
		 me->query("c_name"),targetname ),
		({ me ,target }) );

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration, heal_hp,heal_body,*hp_cond,*body_cond;
	mixed *condis ;

        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster, 
	    "不知怎麽的,也许是觉得你是个蒙古大夫。总之,你的患者走掉了。\n" 
	  );
	  return;
	}
	
	if( dest->query_temp("acup_effect/"+EFFECT_ID) ) {
		tell_object( dest,
			"你觉得体内的血气开始快速流动，但是好像并没有什麽不同....。\n"
		);
	} else {
		tell_object( dest,
	            "你觉得体内的血气开始快速流动，同时全身的伤口开始有些微麻痒！\n"
		);
		boost = level - BASIC_NEEDED + 1 ;		
		if( caster == dest )
			duration = level * 55 + (int)caster->query_stat("pie") * 5;
		else
			duration = level * 45 + (int)caster->query_stat("pie") * 5;

                hp_cond = dest->query("conditions/_heal_hp") ;
                body_cond = dest->query("conditions/_heal_body") ;
                
                heal_hp = hp_cond[0]-(hp_cond[0]*boost/8) ;                
                heal_body = body_cond[0]-boost*2 ;

                if( heal_hp < 1 ) heal_hp = 1 ;
                if( heal_body < 20 ) heal_body = 20 ;
                
                HEAL_HP->apply_effect(dest,heal_hp,hp_cond[1]+boost) ;		
                HEAL_BODY->apply_effect(dest,heal_body,body_cond[1]+boost) ;

		dest->set_temp("acup_effect/"EFFECT_ID, 1);
		
        	tell_room( environment(dest),sprintf(
	        	"不知是不是错觉,你觉得%s的伤口隐隐闪著金色的光芒。\n"
	        	,dest->query("c_name")),dest ) ;
		call_out( "expire", duration, dest, hp_cond, body_cond ) ;
	}
	return ;	 
}

void expire( object player,int *hp_cond,int *body_cond )
{
    if( !player ) return;
    tell_object( player,
		"你觉得伤口的复原不再像以前快，同时气血的流动变得缓和....。\n" );
    HEAL_HP->apply_effect(player,hp_cond[0],hp_cond[1]) ;
    HEAL_BODY->apply_effect(player,body_cond[0],body_cond[1]) ;
    player->delete_temp("acup_effect/"+EFFECT_ID);
    return ;
}

