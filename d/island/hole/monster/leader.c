#include <../hole.h>

inherit REPORT ;
inherit ENEMY ;
void create ()
{
        ::create();
        set_level(19);
        set_name( "Lizardman Leader Bulansido","����ϣ��" );
        add ( "id",({ "lizardman","leader","bulansido" }) );
        set_short( "���������� ����ϣ��" );
        set_long(@LONG
    �㿴������һֻ�޴�������ˣ������������������ߣ���������
β�;��ж����ߣ��ɱ���Ϊ����β��ֻ��װ���õģ�����β�Ϳ�˵��
�൱���µ�����ม�����Ŀǰ�����˴����е����䣬ͳ�������������
������������������λ��ս�ߣ���ȫʤ��ս��������λ����������
����ֳ�Ϊ��ս�񡻡�
LONG
		);
        set( "unit","λ" );
        set( "exp_reward",45000 );
        set( "alignment",3000 );
        set( "wealth/silver",1000 );
        set( "gender","male" );
        set( "race","lizardman" );
        set( "weight",200 );
        set( "max_hp",2000 );
        set( "hit_points",2000 );
        set( "tactic","assault" );
        set( "unbleeding",1 );
        set( "special_defense",([ "all":70,"none":80 ]));
        set( "tactic_func","tail_attack" );
        set_c_limbs(({ "ͷ��","�ؿ�","�ֱ�","����","β��" }) );
        set_perm_stat( "int",15 );
        set_perm_stat( "str",30 );
        set_perm_stat( "dex",30 );
        set_perm_stat( "kar",30 );
        set_perm_stat( "pie",20 );
        set_perm_stat( "con",30 );
        set_natural_weapon( 40,18,35 );
        set_natural_armor( 50,29 );
        set_skill( "dodge",100 );
        set_skill( "longblade",100 );
        set_skill( "parry",100 );
        set_skill( "block",100 );
        set_skill( "tactic",100 );
        wield_weapon( HWEAPON"king_sword" );
        equip_armor( HARMOR"shield2" );
        equip_armor( HARMOR"arms1" );
        equip_armor( HARMOR"cloak1" );
        equip_armor( HARMOR"plate2" );
        equip_armor( HARMOR"helmet1" );
        set( "inquiry",([
        		"halberd" : "@@ask_halberd",
        		"valor" : "@@ask_valor",
        		]) );
}

void init()
{
	::init();
	add_action( "to_report","report" );
	add_action( "to_embattle","embattle" );
	add_action( "to_demand","demand" );
}

int to_embattle()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"����ϣ��ݺݵĵ���"+c_him+"һ��˵����Χ���ң��붼���룬�����ɡ�\n",player );
	tell_object( player,"����ϣ��ݺݵĵ�����һ��˵����Χ���ң��붼���룬�����ɡ�\n" );
	command( "kill "+him );
	return 1;
}

int to_demand()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"����ϣ��ݺݵĵ���"+c_him+"һ��˵�����Ұ��֣��붼���룬�ԹԵ����ɡ�\n",player );
	tell_object( player,"����ϣ��ݺݵĵ�����һ��˵�����Ұ��֣��붼���룬�ԹԵ����ɡ�\n" );
	command( "kill "+him );
	return 1;
}

int tail_attack()
{
    object env,*victim;
    int i;
    env=environment(this_object());
    victim=query_attackers();
    if(!victim) return 0;
    if( random(99)>19 ) return 0;
    tell_room( env,"\n���������� ����ϣ�� �����޴��β��ɨ���ڳ����е��ˡ�\n");
    i=sizeof(victim);
    while(i--)
    {
     if (victim[i]!=this_object())
        {
	 victim[i]->receive_damage(75);
	 report( victim[i] );
        }
    }
    return 1;
}

void ask_halberd()
{
	tell_object( this_player(),@HALBERD

����ϣ��˵����
���������亱�������������Ҳû������

HALBERD
		);
		return;
}

void ask_valor()
{
	object player;
	
	player=this_player();
	if( player->query_temp("lizard_quest/leader") ){
	tell_object( player,@VALOR

����ϣ��˵����
��Ȼ������ʿ�����ѣ����Ҿ͸�����ɣ�������������������﷢��
һ�����������¼����㳡�����߸��ڵ�����������������������Ҷ�
�϶�����ʿ�����ߵĽ��������������������ʬ�жϣ����߶��Ǳ���
ǬѪҺ������������Ƕ���Ϊ�������й�����Ϣ�ڴ��ӵ�ĳ�����䡣
�������ǲ���ȷ���������Ϣ�أ�Ҳ��֪����β�����������Ϊ�˷�
ֹ������Ī����ɥʧ���������Ѿ�����������᳹������������
���飬�ҽ�������ȥ�ɸ������ҿ�������˿������������κ��·���
���ǵ��������ҡ�

VALOR
		);
	player->delete_temp("lizard_quest/leader");
	return ;
	}
	tell_object( player,"����ϣ���û��ɵ��۹⿴���㡣\n" );
	return;
}

int to_report(string arg)
{
	string what,man;
	
	if( !arg || sscanf(arg,"%s to %s",what,man)!=2 )
		return notify_fail( "����ϣ��˵�������ţ�����ʲ���·����𣿡�\n" );
	if( man!="blansido" && man!="leader" )
		return notify_fail( "����û������ˡ�\n" );
	if( what!="vampire" )
		return notify_fail( "��ȷ�������룬�㻹����ȥ���鿴����\n" );
	else
	{
	tell_object( this_player(),@VAMPIRE

����ϣ��˵����
ԭ�����ֵ�����Ѫ����������Ѫ���Ǻ��ѶԸ���һ�ֲ���������
������������Ҫ�õ�ħ����������������һ��ȴû�������ⷽ���֪
ʶ�����룬�����ȥ���������������֪�������������Ѫ����

VAMPIRE
		);
	this_player()->set_temp("lizard_quest/poutiff",1);
	return 1;
	}
}