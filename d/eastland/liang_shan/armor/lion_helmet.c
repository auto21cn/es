#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("lion helmet", "熟钢狮子盔");
        add( "id", ({ "helmet" }) );
        set_short( "lion helmet", "熟钢狮子盔");
        set_long(
                "A lion face helmet .\n",
                "这是一顶采狮子之形制作的盔甲，脑後还有许多黄色的鬃毛 \n"
                "看来十分雄壮威武．\n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 9 );
        set( "defense_bonus", 3 );
        set( "weight", 80 );
        set( "value", ({ 288, "gold" }) );
}



