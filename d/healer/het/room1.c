#include <mudlib.h>
#include <conditions.h>
#include "wang.h"
inherit ROOM;

void init()
{
	add_action("do_pick","pick");
}
void create()
{
 	::create();
        set_short("����");
	set_long(@LONG
�ߵ����������ǰһ�������￪���˸��ֻ���������ȥ��һƬ�����������㣬
��������ݷ������ɾ�����ġ��Ƶġ��׵ġ����ġ��ϵ�����ϡ�еĺ�ɫ�Ļ�������
�����Կ�����ˮͰ��С���ӣ���ͷ�ȵȹ����Ĵ�ɢ������Ȼ����Ļ�������ϸ���չ�
�ġ��Ϸ���Զ������ԼԼ�и�é�ݡ�
LONG
);
	set("light", 1);
	set("exits",([
		"south" : WANG"room2" ,
		"east" : WANG"room7" ,
		"west" : "/d/eastland/forest/4,2.forest", 
	]));
	set("pre_exit_func", ([
	     "west" : "leaving",
	    ]));
	set("item_desc", ([
	     "flower"     : 
"����Ļ����ĺ�Ư������ɫ�Ļ�(blue flower)��������ĺ����ģ���Ҫ�����Щ��\n",
	     "blue flower" : "һ����ɫ�Ļ����������йɵ������㡣�벻��ժ����(pick) ?\n",
	     "red flower" : "һ���ɫ�Ļ�����������Ư�����벻��ժ����(pick) ?\n",
	    ]));

	set( "objects" ,([
	     "boy" : WANG_MOB"boy01"
	]));

	reset();
}


do_pick(string str)
{
	string *arg, color,item,tmp;
	object who;
        string whoname;


	if ( ! str ) 
		return notify_fail("��Ҫժʲ��?\n");

	who = this_player();
	arg = explode(str," ");
	
	if ( sizeof(arg) < 2 )
		return notify_fail("��Ҫժʲ��?\n");

	color = arg[0]; item = arg[1];
	if ( item != "flower" ) 
		return notify_fail("����û�����ֶ�����\n");

	whoname = (string)who->query("c_name");

	switch ( color ) {
	   case "red" :
		tell_object(who,"��ժ��һ��컨�������Ǳ�һ�ţ�û�뵽����ޱȣ�һ��֮�£����ְ������ˡ�\n");
		tell_room(this_object(),
			sprintf("%sժ��һ�仨���漴�ѻ�������\n",whoname));
		break;
	   case "blue" :
		tell_object(who,
"��ѡ��һ����Ư���Ļ��������ժ���������ǲ�С�ı��Աߵ�С���������е�����ġ�\n");
		tell_room(this_object(),
			sprintf("%sժ��һ�仨��\n",whoname));
		call_out("little_poison",8,who);
		break;
	   default :
		tell_object(who,"�⻨��û������ժ��Ļ��ɡ�\n");
		break;
	}
	return 1;
}


int leaving()
{
object who;
	who = this_player();
	if ( (int) who->query_temp("kill_wang") == 0) 
		return 0;
	else { 
		tell_object(who,
"����Ҫ�뿪�⻨��ʱ��һ����Ʈ����.. ����ú����.... \n"
"ͻȻ�����뵽�������ҩʦ�Ļ��ԣ������Ѿ���������!!\n"
		);
		(CONDITION_PREFIX + "simple_poison")->
			apply_effect(who,15,6);
		call_out("again",30,who);		
		who->delete_temp("kill_wang");
	}
	return 0;/* still can leave */
}

void little_poison(object who)
{
	tell_object(who,"���Ȼ�ֱ۽�������... �ոյ�����ԭ�����ж���!!\n");
	(CONDITION_PREFIX + "slow") ->apply_effect(who,5,5);
}

void again(object who)
{
	tell_object(who,"���Ȼһ�������ԭ����ҩʦ�Ķ���ֻ����...\n");
	(CONDITION_PREFIX + "weak") ->apply_effect(who,30,15);
	(CONDITION_PREFIX + "slow") ->apply_effect(who,30,15);

}