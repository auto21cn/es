#include <almuhara.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "ͭ������" );
        set_long(
@C_LONG
�������һ����С��ʯ�ң��������ܿ���һ�ֻ����ǽ�Ϲ�����
����(scroll)����������������ô��ص���������Ϣ֮�ã��ھ����˸�
�ŵĴ�ս�ᣬ�㲻���м�����������Ƶ��ˡ�
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng9"
        ]) );
        add( "item_desc", ([
        	"scroll" :
"�ţ���������������ѧ�ϵ������൱����ม�
��һ��������һ���ˣ�������ɮ�˳������ճ�Ⱥ֮�⣬�ڷ�ѧ����Ӧ���൱֮
���裬�ܲ�����������ɸ�����õģ����Ƕ������ɡ�\n"
	]) );  
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
}

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("�㿴�����������޺���%s��̧����һ��̧�˳�����\n",
				obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("�㿴�����������޺���%s��̧����һ��̧�˳�����\n",
			obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_auction()
{
	return 1;
}