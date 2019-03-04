#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name(" Steel helmet", "高级钢盔");
        add( "id", ({ "helmet" }) );
        set_short( "高级钢盔");
        set_long(
                "这是一顶检验合格的钢制头盔 \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set("material","heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 75 );
        set( "value", ({ 165, "gold" }) );
}



