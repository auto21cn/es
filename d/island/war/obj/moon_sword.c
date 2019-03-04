#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "moon sword", "名刀月残" );
        add( "id",({ "moon","sword" }) );
        set_short( "moon sword", "名刀月残" );
        set_long(@AAA
            这是一把有名的月残刀，据说这是因为铸剑师做好这把剑时
            刚好看到月蚀而命名，和星落刀是一对双剑
AAA
);
        set( "unit", "把");
        set( "weapon_class", 35 );
//        set( "bleeding", 15 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 40 );
        set( "weight", 140 );
        set( "value", ({ 920, "silver" }) );
}



