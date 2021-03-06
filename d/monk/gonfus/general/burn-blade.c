#include <mudlib.h>

#define MARTIAL_NAME "monk/general/burn_blade"
#define GONFU_NAME   "burn-blade"

inherit DAEMON;

int eungon(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");
	if( !weapon || (string)weapon->query("type") != "longblade" ) {
		tell_object(me,"你并未装备适合的武器。\n");
		return 0;
	}

	tell_object(me,set_color(sprintf("\n你默念心法，缓缓地催动真气流转全身，准备使出「%s」!!\n",to_chinese(GONFU_NAME) )		    ,"HIR") );

	tell_room( environment(me), 
		sprintf("%s突然脸上泛起红光，缓缓将%s举起，准备使用%s。\n",me->query("c_name"),weapon->query("short"),to_chinese(GONFU_NAME) )
		, me);

	me->set("attack_skill", MARTIAL_NAME);
        me->delete("defense_skill");
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if ( me->query("monk_gonfu/burn-blade") == 35 )
             me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
        me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
        if( me->query_temp("eungon_times") > 0 ) return;
//        if( me->query_temp("gonfu_top") && !me->query_temp("gonfu_busy") ) return;
        if( !me->query_temp("gonfu_busy") ) return;
        if( me->query_temp("gonfu_top") )
            me->set_temp("gonfu_top",0);
	tell_object(me, 
		set_color( sprintf("\n\n你吸了一口气, 停止使用%s。\n",to_chinese(GONFU_NAME) ),"HIR") );
 
 	tell_room( environment(me),
 		sprintf("%s轻轻的吐出一口气，收式而立。\n",me->query("c_name") )
 		, me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}
