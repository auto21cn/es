#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("gold helmet", "红缀金束发盔");
        add( "id", ({ "helmet" }) );
        set_short( "gold helmet", "红缀金束发盔");
        set_long(
                "A beautiful golden helmet .\n",
                "你看到一顶用金丝盘成的头盔，边缘有醒目的红丝带．美丽且不失其防护能力．\n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "none":1, "magic":2]) );
        set( "weight", 80 );
        set( "value", ({ 260, "gold" }) );
}