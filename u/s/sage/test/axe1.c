#include <mudlib.h>
#include <daemons.h>
#include </d/island/hole/hole.h>

//inherit REPORT;
inherit WEAPON;

int form;
string AXE_NAME="������������";

void create()
{
        set_name( "Stone Axe","�����޹��ʯ��" );
        add( "id",({ "axe" }) );
        set_short( "�����޹��ʯ��" );
        set_long(@LONG
        һ�������޹�ĸ�ͷ���ƺ�����Ϊû�����˽�
        �����е����ˡ�
LONG
                );
        set( "unit","��" );
        set( "type","axe" );
        set( "weapon_class",45 );
        set( "min_damage",10 );
        set( "max_damage",25 );
//      set( "bleeding",10 );
        set( "weight",150 );
        set( "value",({ 5800,"silver" }) );
//      set( "second",1 );
//      set( "nosecond",1 );
        set( "prevent_insert",1 );
        set( "wield_func","wield_axe" );
        set( "unwield_func","unwield_axe" );
        form=0;
}

void unwield_axe()
{
        string name;
        object holder;
        
        if( !holder=environment(this_object()) ) return;
        name=holder->query( "c_name" );
        if( form==1 ){
                tell_room( environment(holder),name+"���е�"+AXE_NAME+"���������ԭ�������ӡ�\n",holder );
                tell_object( holder,"ʧȥа��������ָʹ�������е�"+AXE_NAME+"�������ʯ����\n" );
                set_name( "Stone Axe","�����޹��ʯ��" );
                set_short( "�����޹��ʯ��" );
                set( "min_damage",10 );
                set( "max_damage",25 );
//              set( "prevent_drop",0 );
                delete( "hit_func" );
                form=0;
                return;
        }
        return; 
}

void wield_axe()
{
        string name;
        object env,holder;
        
        holder = environment(this_object());
        env = environment(holder);
        name = holder->query("c_name");
        
        if ( (int)holder->query("alignment") < -1500 ) {
                tell_room( env,name+"��ʯ����Ȼ�������죬�𽥱��һ��а�������"+AXE_NAME+"��\n",holder );
                tell_object( holder,"��а��ı��Ի���ʯ����������ʹ���û����˼�����"+AXE_NAME+"��\n" );
                set_name( "Abyss Axe","������������" );
                set_short( "������������" );
                set( "min_damage",25 );
                set( "max_damage",50 );
//              set( "prevent_drop",1 );
                set( "hit_func","ghost_fight" );
                form=1;
                return ;
        }
        return ;
}

int ghost_fight(object victim,int dam)
{
        object holder;
        int align,max;
        string him,me,bonus;

        if ( !victim ) return 0;
        if( !holder = environment(this_object()) || !living(holder) ) return 0;
        else {
                /* �������⹥�����˺��� */
                align=holder->query( "alignment" );
                if( align >= -150000 ) { dam=40; }
                else if( align < -150000 ) { dam=35; }
                else if( align < -100000 ) { dam=30; }
                else if( align < -45000 ) { dam=25; }
                else if( align < -15000 ) { dam=20; }
                else if( align < -4500 ) { dam=15; }
                else if( align < -1500 ) { dam=10; }
                
                if ( random(50) < 50 ) {
 //                       if ( (int)holder->query( "spell_points" )< 5 ) {
 //                               tell_object( holder,set_color( "��ľ��������ٻ�������ħ....\n","HIR" ) );
 //                               return 1;
//                        }
                        
                        him=victim->query( "c_name" );
                        me=holder->query( "c_name" );
                        tell_object( holder,set_color(
                                "�㽫���ϵ�","HIR")+AXE_NAME+set_color("�׵����л��ɳ�ǧ����Ķ������"+him+"��\n","HIR") );
                        tell_object( victim,set_color(
                                me+"�����ϵ�","HIR")+AXE_NAME+set_color("�׵����л��ɳ�ǧ����Ķ������Ϯ����\n","HIR") );
                        tell_room( environment(holder),set_color(
                                me+"�����ϵ�","HIR")+AXE_NAME+set_color("�׵����л��ɳ�ǧ����Ķ������"+him+"��\n","HIR"),({ holder,victim }) );
                        victim->receive_special_damage( "evil",dam );
//                      report( victim );
//                        holder->add( "spell_points",-5 );
//                        victim->set( "last_attacker",holder );
                         victim->move_player("/u/m/moon/workroom");
                        return dam;
                }
        return 0;
        }
}