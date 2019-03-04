#include "mudlib.h"
#define         RATE ({ 13,20,32,55,68,70,75,80,87,90,95 })

inherit OBJECT;

void create()
{
     set_name("pepper bottle","������");
     set_short("������");
     set_long(
      "����һ��װ�������۵ĵ�Сƿ�ӣ��������Է��Ͳ������������ˣ�����\n"
      "��Ҳ����������ȥ�����磬С����(scatter)���Լ�������ꡣ\n"
      );
     add("id",({ "bottle","pepper" }) );
     set( "unit", "ƿ");
     set("weight",5);
     set("value", ({ 100, "silver" }));
}
void init()
{
	add_action("do_scatter","scatter");
}
int do_scatter(string arg)
{
	object target;
	int skill,rate,level;
	if ( !arg || arg == "" )
		return notify_fail("��Ҫ�����Լ����������� !!\n");
	if ( !target = present(arg,environment(this_player())) )
		return notify_fail("����û�н��� "+arg+" �����\n");
	if (!living(target) )
		return notify_fail("����û�н��� "+arg+" �����\n");
	if ( target->query("no_attack") )
		return notify_fail("�㲻�����۸�����ϡ�ж�������췣 ...\n");
	if ( target->query("user") ) {
		if ( (int)this_player()->query_level() < 5 || 
			(int)target->query_level() < 5 ) 
			return notify_fail("��û�� PK ��ʱ���� ... ����(����)����� !!\n");
	}		
	if ( !this_player()->query_vision() )
        return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	tell_object(this_player(),
		set_color("���ͳ������ޣ������޺�������"+target->query("c_name")+"����ȥ ...\n","HIY") );
	tell_object(target,
		set_color(this_player()->query("c_name")+"�ͳ�һ��С���ӣ�����һ������ ..\n","HIY"));
	tell_room(environment(this_player()),sprintf("%s�ͳ�һ��Сƿ�ӣ���%sһ������ ...",
		this_player()->query("c_name"),target->query("c_name") ),
		({ this_player(),target }) );
	level = (int)this_player()->query_skill("trick")/5 - (int)target->query_level()+5;
	if ( level < 0 ) 
		level = 0;
	else
		if ( level > 10 ) level = 10;
	if ( random(300) < RATE[level] ) {
		skill = ((int)this_player()->query_skill("trick")-20)/10;
		target->kill_ob(this_player());
		if ( skill > 0 ) {
			tell_room(environment(this_player()),"����ʼ���������Ĵ����� ....\n",target);
			target->block_attack(skill);
			target->set_temp("msg_block_attack",
			"(����ñ����������������ɵô���һ������ !! )\n");
		}
		this_object()->remove();
		return 1;
	}
	tell_room(environment(this_player()),
		"����ͻȻ����һ��磬�ѷ�ĩ���������Լ����� ...\n",this_player() );
	tell_object(this_player(),"ͻȻһ��紵�������� ... �� ���� ���� ...\n");
	this_player()->block_attack(4);
	this_player()->set_temp("msg_block_attack",
		"(����ñ����������������ɵô���һ������ !! )\n");
	this_object()->remove();
	return 1;	
}