#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven boots", "精灵鞋");
        add( "id", ({ "boots" }) );
        set_short( "精灵鞋" );
        set_long(
                "这是精灵王用独角兽皮加上精灵族特殊的秘方所烘制成的鞋子 \n"
                "，穿起来既舒适又耐用，相信会给你的脚带来极大的保护。\n"
        );
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "fire":-1 ]) );
                       
        set( "weight", 50 );
        set( "value", ({ 800, "silver" }) );
}
