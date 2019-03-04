#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("stone helmet", "大地之盔");
        add( "id", ({ "helmet" }) );
        set_short("大地之盔");
        set_long(@C_LONG
这是一顶由石头做成的头盔，相传是野蛮人中伟大的战士才能使用的护具。 
它吸收了大地的精华，所以很重但也有极佳的防护力。 
C_LONG
                   );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "stone");
        set( "armor_class", 8 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "fire":3, "cold":-3, "electric":2 ]) );
        set( "weight", 120 );
        set( "value", ({ 80, "gold" }) );
}