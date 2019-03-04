#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "star sword", "名刀星落" );
        add( "id",({ "star","sword" }) );
        set_short( "star sword", "名刀星落" );
        set_long(@AAA
            这是一把有名的星落刀，据说这是因为铸剑师做好这把剑时
            刚好看到流星而命名
AAA
);
        set( "unit", "把");
        set( "weapon_class", 32 );
//        set( "bleeding", 15 );
        set( "type", "longblade" );
        set( "min_damage", 18 );
        set( "max_damage", 32 );
        set( "weight", 140 );
        set( "value", ({ 920, "silver" }) );
}



