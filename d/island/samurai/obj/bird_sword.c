
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "bird sword", "名刀千鸟" );
        add( "id",({ "bird","sword" }) );
        set_short( "bird sword", "名刀千鸟" );
        set_long(@AAA
这是一把有名的古刀千鸟，在剑身上刻有一个飞鸟的图案
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 26 );
        set( "weight", 170 );
        set( "value", ({ 1320, "silver" }) );
}



