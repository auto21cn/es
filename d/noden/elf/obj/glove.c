#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven gloves", "精灵手套");
        add( "id", ({ "glove","gloves" }) );
        set_short( "精灵手套" );
        set_long(
                "这是精灵王用独角兽皮加上精灵族特殊的秘方所烘制成的手套 \n"
                "，穿起来既舒适又耐用，相信会给你的手带来极大的保护。\n"
        );
        set( "unit", "双");
        set( "type", "hands" );
        set( "material", "leather" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );
                       
        set( "weight", 40 );
        set( "value", ({ 800, "silver" }) );
        set( "no_sale", 1);
}
