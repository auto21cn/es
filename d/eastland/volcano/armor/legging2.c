#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("dark leggings", "�ڰ��ּ�");
        add( "id", ({ "leggings" }) );
        set_short( "�ڰ��ּ�");
        set_long(
                "����ּ����Ǿ�������֮�ڰ���Ԩ�����ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "legs" );
        set( "material", "light_metal");
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 200, "gold" }) );
}





