
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "willow club", "白杨棍");
        add ("id",({ "club"}) );
        set_short("白杨棍");
        set("unit", "把");
        set_long(@C_LONG
这把白杨棍是利用白杨质轻的特性制成的，是初学棍法的人的最佳选择。
C_LONG
        );
        set( "weapon_class", 11 );
        set( "type", "bo" );                        
        set( "min_damage", 8);
        set( "max_damage", 14);
        set( "weight", 45 );
        set( "value", ({ 180, "silver" }) );
}
