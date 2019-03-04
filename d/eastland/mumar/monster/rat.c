#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(14);
        set_name( "big rat", "������" );
        add( "id", ({ "rat" }) );
        set_short( "������" );
        set_long(
            "����һֻ�ߴ�ǿ׳�����󣬿������Ѿ��е����������ܳԵ�ȫ�Թ��ˡ�\n"
            "��������ſ��һ���״���˯���������û���գ���ò�Ҫ��������\n");
        set( "unit", "ֻ" );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 5 );
        set_natural_weapon( 35,20,35 );
        set_natural_armor( 75,28 );
        set_skill( "dodge", 70 );
        set( "alignment", -500 );
        set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "β��" }) );
        set_c_verbs( ({ "%s�ſ����죬��%sһ��ҧ��",
          "%s������������ǰ֫��%sͷ��һ����ȭ", "%s����������β��ɨ��%s"}) );
        set("c_death_msg",
          "%s ����һϢ��˵�������˼�..�˼һ�û�Ա���...����Ȼ��͵��ز�����..\n" );
}
 
void die()
{
        object killer;
 
        killer = query("last_attacker");
        if( killer ) killer->set_temp("mumar/done",1);
        ::die();
}