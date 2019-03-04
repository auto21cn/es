//�������ǲο�/d/thief/hall/misc/knife.c ��ԭ����
//�ڴ˸�лԭ����aqaurius                     
//                                               Takeda �95��11 ��

#include <mudlib.h>
#define SKIN_OBJ "/d/adventurer/hall/obj/skin"
#define MAKE_SKILL "anatomlogy"
inherit OBJECT;

init()
{
	add_action("do_cut","cut");
}

void create()
{
	seteuid(getuid());
	set_name( "knife","��ƤС��" );
	set_short( "��ƤС��" );
	set_long( @LONG
    ����һ���ᱡ������С��, ����ȡëƤ���˳��õĹ���֮һ��
������� cut skin from corpse ȡ��Ұ�޵�Ƥ��
LONG
	);
	set( "weight",10 );
	set( "unit","��");
	set( "value",({ 230,"silver" }));
}
int check_skill(object me)
{
	int skill1,skill2,rate;
	if ( (string) me->query("class") != "adventurer" ) 
		return 0;
	if ( ( skill1 = (int) me->query_skill(MAKE_SKILL) ) == 0 )
		return 0;
	if (random(skill1 + (int) me->query_stat("piety") ) > 20 )
		return 1;
	else 
		return 0;
}

int query_sp_cost(object me)
{
	return ( 80 - (int)me->query_skill(MAKE_SKILL) ) ;
}

do_cut(string arg)
{
	string *args,tmp;
	int sz,i,skill;
	object *inv,env,skin,corpse,mob;

	if ( ! arg ) 
		return notify_fail("����Ҫ��ʲ��?\n");
	if ( sscanf(arg,"skin from %s",tmp) != 1)
		return 0;
	if ( !this_player()->query_vision() )
		return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	env = environment(this_player());
	if ( ! (corpse = present(tmp,env)) ) 
		return notify_fail("����û�����֡��� ��\n");
        if (sscanf((string)corpse->query("short"),"%s��ʬ��",tmp) < 1 || tmp =="����") {
		return notify_fail("��ʬ���Ѿ�������, ���������?? \n");
	}
	if ( (i = query_sp_cost(this_player())) > (int)this_player()->query("spell_points") ) {
		return notify_fail("�㾫����̫����, �޷������־�ϸ�Ĺ�����\n");
	}

	this_player()->add("spell_points",-i);
	if ( ! (tmp = (string) corpse->query("npc")) ) 
		return notify_fail("����Ƥ��,���������Ƥ����Ʒ�ʲ��Ǻܺá�\n");
	mob = new(tmp);
	if ( nullp(mob) ) {
		write("����� bug, ��֪ͨ��ʦ!\n");
		return 1;
	}

	if ( check_skill(this_player()) ) {
		tell_room(env,sprintf("%s��ʬ���ϻ�����, ȡ��һ��Ƥ��\n",this_player()->query("c_name") ), this_player() );
		write(sprintf("��С�������Ĵ�ʬ���ϰ���һ��Ƥ��\n",(string)mob->query("c_name") ));
		skin = new(SKIN_OBJ);	
		skin->set_short(mob->query("short")+"��Ƥ");
		skin->set("skin_level", mob->query_level() );
		skin->set("c_skin_name",mob->query("short") );
		skin->set("make_skill",(int)this_player()->query_skill("anatomlogy"));
		skin->add("extra_ids",mob->query("id"));
		skin->move(this_player());
		corpse->remove();
		mob->remove();
		return 1;
	} else {
	tell_room(env,sprintf("%s������ʬ����ȡ��Ƥ, ���ʧ����!\n",this_player()->query("c_name") ), this_player() );
		corpse->remove();
		mob->remove();
		return notify_fail("��һ����С��, ���Ƥ, ��������!!\n");
	}
	return 0;
}
