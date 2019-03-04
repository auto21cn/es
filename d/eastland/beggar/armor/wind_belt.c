#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name( "wind belt", "束云腰带" );
        add( "id", ({ "wind","belt" }) );
        set_short( "束云腰带" );
        set_long(@C_LONG
束云腰带是由天然蚕丝编织而成的,上面绣有一大片浮云因之而命名为束云腰带。
束云腰带是由震八方死去的妻子制成给他的, 对他而言等於无价之宝,虽然不乏识
货的人问津,可是震八方怎麽也不肯割爱。       
C_LONG
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 50 );
        set( "value", ({ 150, "gold" }) );
}
