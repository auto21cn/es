
#include "../goomay.h"

inherit MONSTER;

void create()
{
        object ob1,ob2;
        ::create();
        set_level(15);
        set_name( "guard of mine", "�������" );
        add ("id", ({"guard",}) );
        set_short( "�������" );
        set_long(
        "����һ������ʮ����׳����Ŀ������������������Ӻͱ����󹤵İ�ȫ\n"
        "���˿��������µش������㣬���������񾯸��㲻Ҫ����̫����\n"
        );
	set("alignment",400);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "unit", "��" );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "str", 23 );
        set_perm_stat( "int", 17 );
        set_perm_stat( "con", 20 );
        set_perm_stat( "piety", 15);
        set_perm_stat( "karma", 17);
        set_skill("thrusting",70);
        set_skill("parry",70);
        set ("max_hp", 470);
        set ("hit_points", 470);
        set ("wealth", ([ "gold": 10 ]) );
        set_natural_weapon(19,10,25);
        set_natural_armor(35,15);
	set ("weight", 400);
	wield_weapon(Obj"iron_spear");
        equip_armor(Obj"iron_plate");


        set( "inquiry", ([
                "С��" : "@@ask_forsy",
		"forsy" : "@@ask_forsy"]));

}

int appear_forsy(object who)
{
        object ob;

	ob = new( "/d/eastland/goomay/monster/forsy" );
	if( environment(this_object())->query("forsy_appear")!=1 )
	return 0;
        tell_room( environment(), 
	"������һ�������ת������һ��̨�������Ĵӿ���������\n"
        "һ������һ��ʮ�ָ�����Ẻ�ӣ�����һ����ɰ���˳��� ...\n" ,
	this_object() );
	ob->move(environment(this_object()));
	environment(this_object())->set("forsy_appear",2);
        return 1;
}

int ask_forsy()
{
        if( (int)this_player()->query_quest_level("Goddess_statue") != 1 ){
                tell_object(this_player(),
			"�����ܲ��ͷ��ص�����С�ģ�����С����ɶ����\n" );
                return 1;
		}
        if ( this_player()->query_temp("get_paper") ) {
        tell_object(this_player(),
        "�����ܲ��ͷ��ص������㲻���Ѿ����������𣿡�\n" );
        return 1;
        }
	
	if ( environment(this_object())->query("forsy_appear")==1  ) {
		tell_object(this_player(),
			"�����ܲ��ͷ��ص�������ʲ�� !! �Ѿ�������ˣ��š����ǲ��������𣿡�\n" );
		return 1;
	}
	
	if ( environment(this_object())->query("forsy_appear")==2  ) {
		tell_object(this_player(),
			"�����ܲ��ͷ��ص�:��С��С��, ������쾻����Ҫ��С��? �����ڲ�����!��\n");
		return 1;
	}
		
tell_object(this_player(),
@C_WU
��������һ���۾�����������´����㣬��һ�������ص���������
���ˣ��� !! ��������С�������㵱�����˵�����Ժ� !!��

�������������������һ�����ӣ�һ��������������ߵĿ�ӿ�
ԶԶ������
C_WU
		);
        environment(this_object())->set("forsy_appear",1);
        call_out("appear_forsy", 5,this_object());
        return 1;
}
