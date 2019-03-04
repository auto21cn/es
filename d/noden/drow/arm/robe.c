#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("snake skin robe", "蹂蛇皮长袍");
   add( "id", ({ "robe" }) );
        set_short( "蹂蛇皮长袍" );
        set_long(
@C_LONG
这是一件已经过处理的软皮革的长袍，能有效地覆盖住你的身体并
且避免伤害，是黑暗精灵手工艺的代表作。
C_LONG
        );
        set( "unit", "件");
        set( "type", "body" );
        set( "material", "leather" );
        set( "armor_class", 14 );
   set( "defense_bonus", 8 );
        set( "special_defense",
               ([ "poison":6 ]) );
        set( "weight", 130 );
        set( "value", ({ 1000, "silver" }) );
}
