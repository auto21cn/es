#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper feet ring", "黄铜足环");
        add( "id", ({ "ring","boots" }) );
        set_short( "黄铜足环" );
        set_long(
@C_LONG
这是一对用黄铜打造的脚环，是黑暗精灵特有的产品，它能紧密的
扣住你的足踝，可以预防伤害。
C_LONG
        );
        set( "unit", "对");
        set( "type", "feet" );
   set( "material", "light_metal" );
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 70 );
        set( "value", ({ 260, "silver" }) );
}
