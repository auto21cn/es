#include <mudlib.h>

#define GONFU_DIR    "scholar/"
#define GONFU_NAME   "tanlo"

inherit DAEMON;

int enhant(object me, int level)
{
	tell_object(me, can_read_chinese(me)?
		"\n�㿪ʼ��������춽ż�, ׼��ʹ����"+
		to_chinese(GONFU_NAME)+"��!!\n":
		"You prepare to use "+GONFU_NAME+" step!!\n");

	tell_room( environment(me), ({
		"\n"+me->query("cap_name")+" is preparing to use "+GONFU_NAME+
		" gonfu!\n", "\n"+me->query("c_cap_name")+
		"ͻȻ����һ�䣬�Ų���֪��������˳�������������\n" }), me);

	me->set("defense_skill", GONFU_DIR+GONFU_NAME); 
	me->delete("attack_skill");
	me->set_temp("gonfu_busy",1);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	tell_object(me, can_read_chinese(me)?
		"������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n":
		"You make a deep breath, stop using "+GONFU_NAME+" step!\n");
 
 	tell_room( environment(me),({
 		me->query("cap_name")+" makes a deep breath, stops using "+
 		GONFU_NAME+" step!\n", me->query("c_cap_name")+
 		"�Ų��𽥻���, ���ͣ��������\n" }), me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}