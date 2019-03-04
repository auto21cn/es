
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja sword", "忍者刀" );
        add( "id",({ "sword" }) );
        set_short( "Ninja sword", "忍者刀" );
        set_long(@AAA
忍者专用的武器，虽说名称是刀但却比平常的刀要短了许多，
或许是忍者为了方便移动而改的吧
AAA
        );
        set( "unit", "把");
//        set( "bleeding",13);
        set( "weapon_class", 25 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 25 );
        set( "weight", 120 );
        set( "value", ({ 720, "silver" }) );
}



