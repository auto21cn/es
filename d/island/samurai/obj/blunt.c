
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Club", "木棍" );
        add( "id",({ "club" }) );
        set_short( "club", "木棍" );
        set_long(@AAA
这是市场警卫所用的木棍
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 22 );
        set( "type", "blunt" );
        set( "min_damage", 7 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}



