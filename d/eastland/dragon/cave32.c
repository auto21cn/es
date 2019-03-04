
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ɭ��");
	set_long( @LONG_DESCRIPTION
������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶���ɣ���ݷ�������
�����µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ�������в����ܷҶྫ��޹�գ���
һ���ж���ð���ߵ��ģ���֪������ƽ��������
LONG_DESCRIPTION
	);
	set_outside("dragoncave");
	set( "light", 1 );
	set( "exits", ([
		"east"  : Lcave"cave18"
	]) );
	reset();
}

void init()
{
 add_action("do_search","search");
 }

int do_search(string arg)
{
	object ob1,ob2,ob3;
	
	ob1=(object)Lcave"cave18"; 
    if (!arg) arg="here";
	if( arg!="here")
		return notify_fail( 
			"����������������ȥ������û���ҵ��κ����صĶ�����\n");

    else if ((int)ob1->query("room_control")==2&& !ob1->query("tree_find"))  {
        ob2=new(Lditem"layuter_tree");
        ob3=environment(this_player());
        ob2->move(ob3);
		write("һ�����ص���ͻȻ�������ǰð����\n");

		ob1->set("tree_find",1);
		return 1;
	}
	return notify_fail( 
		"����������������ȥ������û���ҵ��κ����صĶ�����\n");

}