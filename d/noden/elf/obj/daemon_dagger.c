
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "demonic dagger", "恶魔匕首" );
        add( "id",({ "dagger"}) );
        set_short( "恶魔匕首" );
        set_long(
            "这是恶魔小偷的专用武器。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 17 );
        set( "type", "dagger" );
        set( "min_damage", 8 );
        set( "max_damage", 17 );
        set( "second",1);
        set( "weight", 100 );
        set( "value", ({ 1200, "silver" }) );
}

