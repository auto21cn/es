#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("small dagger", "小匕首");
        add ("id",({ "dagger"}) );
        set_short("小匕首");
        set_long( @CLONG
这把匕首原来是小恶鬼所持有的, 看起来相当地小巧。
CLONG
        );
        set("unit","把");
        set( "weapon_class", 6 );
        set( "type", "dagger" );
        set( "min_damage", 3 );
        set( "max_damage", 6 );
        set( "weight", 30 );
        set( "value", ({ 10, "silver" }) );
}
