#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/dragon_claw"
#define GONFU_NAME   "dragon-claw"

inherit DAEMON;

int eungon(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");
	if( weapon && (string)weapon->query("type") != "unarmed" ) {
		tell_object(me, 
			"你装备了不适合的武器。\n");
		return 0;
	}

	tell_object(me, 
        set_color("\n『看我的厉害!!!』你运功\於指，准备使出少林绝招「"+
		to_chinese(GONFU_NAME)+"」!!\n", "HIR") );
	tell_room( environment(me), 
		"\n"+me->query("c_name")+"长啸一声，"+
		"双手形如龙爪，似乎准备使出某种厉害的功\夫。\n", me);

	me->set("attack_skill", MARTIAL_NAME); 
        me->delete("defense_skill");
       	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if ( me->query("monk_gonfu/dragon-claw") == 35 )
             me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 30+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
        me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
        if( me->query_temp("gonfu_top") && me->query_temp("eungon_times") > 0 ) return;
        if( !me->query_temp("gonfu_busy") ) return;
        if( me->query_temp("gonfu_top") )
            me->set_temp("gonfu_top",0);
	tell_object(me, 
		set_color("\n\n你吸了一口气, 停止使用"+to_chinese(GONFU_NAME)+"。\n","HIR") );
 	tell_room( environment(me),
 		me->query("c_name")+"轻轻的吐出一口气，收式而立。\n" , me);
 
	me->delete("attack_skill");
	me->delete_temp("gonfu_busy");
}
