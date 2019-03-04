#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/gi_mei"
#define GONFU_NAME   "gi-mei"

inherit DAEMON;

int eungon(object me, int level)
{
	if( (int)me->query("load") > (int)me->query("max_load") ) {
		tell_object( me, 
			"��Я��̫�ණ��, �޷�ʩչ����!\n" );
		return 0;
	}
	tell_object(me, 
		"\n�������𼺣�����Ϊ�֡���ȫ���˹�\��׼��ʹ����"+
		to_chinese(GONFU_NAME)+"��!!\n" );

	tell_room( environment(me), 
		me->query("c_name")+
		"��̾һ����˫�ƺ�ʮ��׼��ʹ��"+to_chinese(GONFU_NAME)+"��\n", me);

	me->set("defense_skill", MARTIAL_NAME); 
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if( me->query("monk_gonfu/gi-mei") == 35 )
            me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 20+level, me);
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
		"\n\n������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n" );
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"������³�һ��������ʽͣ����\n", me);
 
// 	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}