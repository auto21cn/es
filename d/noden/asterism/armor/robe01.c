#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("holy robe", "ʥ��");
        add( "id", ({ "robe" }) );
        set_short( "ʥ��");
        set_long(
                "����һ��������ؾ���ʥ�����ķ��ۡ������·�����ҫ����ɫ�ķ��š�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","cloth");
        set( "armor_class", 35 );
        set( "defense_bonus", 5 );
        set("special_defense",
              (["fire":10,"cold":-10,"evil":15,"divine":-15,"magic":10]) );
        set( "weight", 170 );
        set( "value", ({ 220, "gold" }) );
}

