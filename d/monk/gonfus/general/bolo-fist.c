#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/bolo_fist"
#define GONFU_NAME      "bolo-fist"

inherit DAEMON;

int eungon(object me, int level)
{
	
	if( (object)me->query("weapon1") ) {
		tell_object(me, 
			"你装备了不适合的武器。\n");
		return 0;
	}

	tell_object(me, 
	set_color( "\n你默念神功\口诀，准备使出「"+
		to_chinese(GONFU_NAME)+"」!!\n", "HIG") );
	tell_room( environment(me), 
		"\n"+me->query("c_name")+
		"深深的吸了一口气，运气於臂，准备使出"+to_chinese(GONFU_NAME)+"。\n", me);

	me->set("attack_skill", MARTIAL_NAME); 
        me->delete("defense_skill");
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if ( me->query("monk_gonfu/bolo-fist") == 35 )
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
		set_color("\n\n你吸了一口气, 停止使用"+to_chinese(GONFU_NAME)+"。\n","HIG") );
 	tell_room( environment(me),
 		me->query("c_name")+"轻轻的吐出一口气，收式而立。\n" , me);
 		
	me->delete("attack_skill");
	me->delete_temp("gonfu_busy");
}
