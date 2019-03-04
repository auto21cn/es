#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Hell Blessed suit","幽冥之袍" );
        add( "id", ({ "suit","cloth" }) );
        set_short( "幽冥之袍" );
        set_long(
                "你看到这件袍子上面写了几个字: 黑帝斯出品，品质保证。\n"
        );
        set( "unit", "领" );
        set("material","cloth");
        set( "type", "body" );
        set( "armor_class", 33 );
        set( "defense_bonus", 5 );
        set( "weight", 70 );
        set( "value", ({ 1700, "silver" }) );
}
