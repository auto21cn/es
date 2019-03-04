#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("golden scalemail", "黄金索子甲");
        add( "id", ({ "mail" }) );
        set_short("黄金索子甲");
        set_long(
                "这件护甲乃是用一片片的黄金紧密缝合而成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "heavy_metal");
        set( "armor_class", 35 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":10 ]) );
        set( "weight", 250 );
        set( "no_sell",1);
        set( "value", ({ 400, "gold" }) );
}
