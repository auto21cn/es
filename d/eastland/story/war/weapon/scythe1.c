#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "blood scythe", "Ѫ����" );
    add( "id", ({ "scythe" }) );
    set_short( "Ѫ����" );
    set_long(@LONG
һ��մ��Ѫ�����������������ֳ��ɫ��
LONG
    );
    set( "unit", "��" );
    set( "weight", 40 );
    set( "value", ({ 800, "silver" }) );
    setup_weapon("longblade", 20,14,22);
}
