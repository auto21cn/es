
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "star sword", "��������" );
        add( "id",({ "star","sword" }) );
        set_short( "star sword", "��������" );
        set_long(@AAA
            ����һ�����������䵶����˵������Ϊ����ʦ������ѽ�ʱ
            �պÿ������Ƕ�����
AAA
);
        set( "unit", "��");
        set( "weapon_class", 30 );
//        set( "bleeding", 15 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 140 );
        set( "value", ({ 920, "silver" }) );
}


