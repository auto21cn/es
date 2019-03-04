// Created by Aquarius@EasternStory
#include <mudlib.h>
inherit OBJECT;
int be_stick ;

void create()
{
     be_stick = 0;
     seteuid(getuid());
     set_name("scotch tape","���ƽ���");
     add("id",({"tape"}));
     set("short","@@query_short");
     set_long(@LONG
һ�����ƽ���, ��Գ�ǿ, ��ˮ������, ��������Ǯ�� 
ʹ�÷��� : stick tape on <something>." 
LONG );
     set( "unit", "��");
     set("weight",1);
     set("value", ({ 40, "silver" }));
//     set("amount",1);
}

string query_short()
{
    if ( be_stick == 0 ) {
    	return "���ƽ���";
    } else {
	if ( this_player() == environment(this_object()) ) 
		return "һ�����������ϵ����ƽ���";
	else
		return sprintf("һ������%s���ϵ����ƽ���",environment(this_object())->query("c_name")) ;
    }	
}

void init()
{
	if ( be_stick ) {
		add_action("do_tear","tear");
		add_action("do_say","say");
		add_action("do_say","shout");
		add_action("do_say","cast");
		add_action("do_say","whisper");
		add_action("do_say","knight");
		add_action("do_say","monk");
		add_action("do_say","scholar");
		add_action("do_say","adv");
		add_action("do_say","mage");
		add_action("do_say","healer");
		add_action("do_say","tell");
		add_action("do_say","es");
		add_action("do_say","chat");
		add_action("do_say","songin");
	} else if ( userp(this_player()) ){
		add_action("do_put","stick");
	}
}

int do_say(string arg)
{
	if ( ! be_stick ) return 0;
	write("��Ĵ���ͱ�����(tape)��ס��, �Ȱѽ���˺(tear)�����ɡ�\n");
	tell_room(environment(previous_object()),sprintf("%s֧֧����Ĳ�֪����˵ʲ�ᡣ\n",previous_object()->query("c_name")),previous_object());
	return 1;
}

int do_tear(string arg)
{
	if ( ! id(arg) ) return 0;
	write("��˺�½�����\n");
	tell_room(environment(this_player()),this_player()->query("c_name")+"˺�½�����\n",this_player());
	this_player()->delete_temp("silence");
	return this_object()->remove();
}

int npc_do_tear(object me)
{	
	if (me) {
	tell_room(environment(me),me->query("c_name")+"˺�½�����\n");
	me->delete_temp("silence");
	}
	return this_object()->remove();
}

int do_put(string arg)
{
	object env,dest,me;
	int skill,succeed;
	string name,ob_name;
	if( be_stick==1 ) return notify_fail("�⽺���Ѿ���ʹ�����ˡ�\n");
	if ( sscanf(arg,"%s on %s",ob_name,name) != 2 ) return 0;
	if ( ! id( ob_name ) ) return notify_fail("��ʲ�� ?\n");
	me = this_player();
	env = environment(me);
	dest = present(name,env);
	if ( me->query_temp("doing_backstab") )
		return notify_fail("������Ҫ������ˣ�û�շ���ȥ��������\n");
	if ( me->query_current_attacker() ) {
		return notify_fail("����æ��ս��, ���п���������?\n");
	}
	if ( ! dest ) return notify_fail(name+"������ߡ�\n");
	if ( ! living(dest) ) {
		write("���ý�����"+dest->query("c_name")+"�����ܲ�ͨ�硣\n");
		tell_room(env,sprintf("%s��������, ��%s������һͨ��\n",me->query("c_name"),dest->query("c_name") ),({me}));
		this_object()->remove();
		return 1;
	}
/* 	since player �������ụ k, we don't have to check that ..
	if ( (int) me->query_level() < 5 ) {
		return notify_fail("��ĵȼ�̫����, ��ò�Ҫ����...\n");
	}
*/
	if ( userp(dest) && (int)dest->query_level() < 5 ) {
		return notify_fail("�벻Ҫ�۸���С..\n");
	}

	if ( dest == me ) {
		tell_room(env,sprintf("%s�ý������Լ��������������\n",me->query("c_name")),me);
		write("���ý�����ס�Լ�����͡�\n");
		be_stick = 1;
		this_object()->move(dest);
		this_object()->set("extra_look", "$N�Ĵ�����ϲ�֪����˭���˽�����\n");
		this_object()->set("prevent_drop",1);
		this_object()->set("prevent_insert",1);
		this_object()->set("long","����������ס������, �����˺����!(tear tape)\n");
		return 1;
	}

	// max value of skill : lv 19 vs. lv 1 => 160 ( 19+24+18+100)
	skill = (int) me->query_stat("int")-(int) dest->query_stat("int");
	skill += (int) me->query_stat("kar")-(int) dest->query_stat("kar");
	skill -= (int) dest->query_level();
	skill += (int)me->query_skill("trick");
	succeed = ( skill > random(110) );

	write("�����������а��Ц��, ����"+dest->query("c_name")+"ЦһЦ..\n");
	tell_room(env,me->query("c_name")+"����������а��Ц��, ����"+
		dest->query("c_name")+"ЦһЦ...\n",({me,dest}));
	tell_object(dest,me->query("c_name")+"����������а��Ц��, ����ЦһЦ..\n");

	if ( dest->query("no_attack") ) 
		return notify_fail( dest->query("c_name")+"����ЦһЦ˵�� : С����, �����������!\n");

	
	if ( succeed ) {
		write(sprintf("%s����������Ц����\n",dest->query("c_name")));
		tell_room(env,sprintf("%s����%s���ĵ�΢Ц����\n",dest->query("c_name"),me->query("c_name")),({dest,me}));
		tell_object(dest,sprintf("�����%s����Ц����\n",me->query("c_name")));
		be_stick = 1;
		tell_room(env, set_color(sprintf("\nͻȻ%s��Ѹ�ײ����ڶ����ٶ��ͳ�һ������,������˵����%s!!\n",me->query("c_name"),dest->query("c_name")),"HIY"),({me,dest}));
		write(set_color("\n����Ѹ�ײ����ڶ����ٶ��ͳ�һ������,������˵����"+dest->query("c_name")+"\n","HIY"),me);
		tell_object(dest,set_color("\n"+me->query("c_name")+"��Ѹ�ײ����ڶ����ٶ��ͳ�һ������,������˵����������!!\n","HIY"));

		this_object()->move(dest);
		this_object()->set("extra_look", "$N�Ĵ�����ϲ�֪����˭���˽�����\n");
		this_object()->set("prevent_drop",1);
		this_object()->set("prevent_insert",1);
//		this_object()->set("short","һ��������ĳ������ϵĽ���");
		this_object()->set("long","����������ס������, �����˺����!(tear tape)\n");
		if ( ! userp(dest) ) {
			me->kill_ob(dest);
			dest->kill_ob(me);
		}
		dest->block_attack( (skill > 60 ? 4 : 2) );
		dest->set_temp("msg_stop_attack",
			"( �㼱��˺������, û�취���� ! )\n");
		dest->set_temp("silence");
		if ( ! userp(dest) )  // npc �Զ�˺��, player �Լ��ֶ�˺�� !
//			call_out("npc_do_tear",6,dest );
			call_out("npc_do_tear",4 + skill/20 ,dest );
	} else {
	    if ( ! userp(dest) ) {
		tell_room(env,sprintf("%sͻȻ���һ��: �����ֵ��С��, ȥ���� !!\n",dest->query("c_name"),me->query("c_name")),({me,dest}));
		write(sprintf("%sͻȻ���һ��: �����ֵ��С��, ȥ���� !!\n",dest->query("c_name")));
		tell_object(dest,sprintf("�㷢��%s���㲻������, ��Ƿ���������\n",me->query("c_name")));
		me->kill_ob(dest);
		dest->kill_ob(me);
		me->set_temp("msg_stop_attack","( ��һ����æ����, û�취����! )\n");
		me->block_attack( 2 );
	   } else {
		write( sprintf("�����ͼ��ʶ����,%s����ЦһЦ˵�� : С����, �����������!\n",dest->query("c_name")) );
		tell_object(dest, sprintf("%s�ƺ���ʲ����ͼ��\n",me->query("c_name")) );
	   }
	}
	return 1;
}
