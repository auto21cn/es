#include "mudlib.h"
#define         RATE ({ 13,20,32,55,68,70,75,80,87,90,95 })

inherit CONTAINER;

void create()
{
	::create();
	set_name("bag", "�鲼��");
	set_short("�鲼��");
	set_c_open_long("����鲼����С͵������װ����Ĵ��ӣ��ֿ��ִ�ģ�\n������ʺ�������\����(wrap)�氢³�͡�\n");
	set( "weight", 20);
	set( "weight_apply", 50 );
	set( "max_load", 300);
	set( "value", ({ 220, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}

void init()
{
	add_action("do_wrap","wrap");
}
int do_wrap(string arg)
{
	object target, *members, *actor, me, leader_ob;
	string leader;
	int skill,rate,level,i;

	me = this_player();
	if ( sizeof(all_inventory()) ) return notify_fail("��Ѵ��ӿ���������\n");
	if ( !arg || arg == "" ) 
		return notify_fail("��Ѵ��Ӿ�������\n");

	if ( !me->query_vision() )
	        return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	if ( !target = present(arg,environment(me)) )
		return notify_fail("����û�н��� "+arg+" �Ķ�����\n");
	if ( !living(target) )
		return notify_fail("����û�н��� "+arg+" �����\n");	
	if ( target->query_attacker() ) 
		return notify_fail("�Է����ں��˴�ܣ����Ҳ���������֡�\n");
	if ( target->query("no_attack") )
		return notify_fail("�㲻�����۸�����ϡ�ж�������췣 ...\n");
	if ( target->query("user") ) {
		if ( (int)me->query_level() < 5 || 
			(int)target->query_level() < 5 ) 
			return notify_fail("��û���۸�����ʱ���� ... ����(����)����� !!\n");
	}
	if ( !leader = me->query_temp("leader") ) 
		return notify_fail("ҪΧ¯Ҳ�����Һð����� !! �� Party �� !!\n");
	if ( !leader_ob = find_player(leader) )
		return notify_fail("��Ķӳ����� !! ���� Party �� !!\n");
	members = leader_ob->query_temp("party_members") ;
	actor = ({ });
	for ( i = sizeof(members)-1 ; i >= 0 ; i--) {
		if ( environment(members[i]) == environment(me) )
			actor += ({ members[i] });
	}
	if ( sizeof(actor) < 2 ) 
		return notify_fail("ֻ����һ�����ڳ��� ... ����Χ¯����\n");
	
	actor -= ({ me });
	
	tell_object(me,
		set_color("������һ����������"+target->query("c_name")+"����ȥ ...\n","HIY") );
	tell_object(target,
		set_color(me->query("c_name")+"ͻȻ����һ�������������ͷ���ֹ��� ..\n","HIY"));
	tell_room(environment(me),set_color(me->query("c_name")+"ͻȻ����һ���鲼������"+target->query("c_name")+"��ͷ������ȥ ...\n","HIY"),
		({ me,target }) );
	rate = (int)me->query_skill("trick") + (int)me->query_skill("hide") 
		+ (int)me->query_skill("sneak");
	rate += ((int)me->query_stat("dex") + (int)me->query_stat("kar") -
		 (int)target->query_stat("dex") - (int)target->query_stat("kar"))*10;
	level = (rate * (int)me->query_skill("trick"))/7000 ;
	if ( level < 0 ) 
		level = 0;
	else
		if ( level > 10 ) level = 10;
	target->kill_ob(me);
	if ( wizardp(me) )
		tell_object(me,sprintf("rate = %d , RATE = %d \n",rate,RATE[level]));
	if ( random(100) < RATE[level] ) {
		skill = (int)me->query_skill("trick")/10
			+ ((int)me->query_stat("kar")
			+ (int)me->query_stat("str")
			- (int)target->query_stat("str")
			- (int)target->query_stat("kar"))*2;
		if ( skill < 0 ) skill = 0;
		if ( skill > 60 ) skill = 60;
		
		tell_room(environment(me),
			sprintf("%s���ָ�������ֻ����%s�� : Χ��¯��ඡ� ....\n",target->query("c_name"),me->query("c_name"))
			, ({ target, me }));
		tell_object(me,target->query("c_name")+"���㶵��ڷ��� ... �ǺǺ� ������ �н��� ...\n");
		tell_object(target,"���������㿪 ... ��ǰ��ʱһƬ��� �������� !! �ɶ�ļһ� !!\n");
		if ( wizardp(me) ) tell_object(me,"block "+(4+(skill/15)*2)+"\n");
		target->block_attack(4+(skill/15)*2);
		target->set_temp("msg_stop_attack",
			set_color("(�㱻���ò�����ס������ƴ�������� !! )\n","HIY",target));
		me->block_attack(4+(skill/15)*2);
		me->set_temp("msg_stop_attack",
			set_color("(����ʹ�����ò�����ס"+target->query("c_name")+"���ϺǺ� ������ ������Ұ�� !! )\n","HIC",me));


		this_object()->remove();
		return 1;
	}
	tell_room(environment(me),
		"����"+target->query("c_name")+"ͻȻ���Ա�һ���������˸��� ...\n", ({ me,target }) );
	tell_object(me,target->query("c_name")+"ͻȻ���Ա�һ�������� ... �� ���� �ܴ���...\n");
	tell_object(target,"�㼱æ���Ա�һ�����������˸��գ��ɶ�ļһ� !! ���� !!\n");
	return 1;	
}