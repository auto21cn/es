#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("Saiyada shield", "赛亚达之盾");
        add( "id", ({ "shield" }) );
        set_short( "赛亚达之盾" );
        set_long(
@C_LONG
这是仿自传说中的战士－赛亚达所拥有的盾牌，而由邪术师奇姆所
打造的复制品，它的形状为一细长的绫型，并在边缘有雕许多的咒
文，能有效提攻魔法防御。
C_LONG
        );
        set( "unit", "面");
        set( "type", "shield" );
        set( "material", "light_metal" );
   set( "armor_class",9);
        set( "defense_bonus", 5 );
        set( "special_defense",
          ([ "poison":15, "fire":12, "cold":-10 ]) );
         set( "weight", 100 );
        set( "value", ({ 1300, "silver" }) );
        set( "no_sale", 1);
}
