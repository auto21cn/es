
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Samurai＿short＿dagger", "武士短刃" );
        add( "id",({ "dagger" }) );
        set_short( "Samuria＿short＿dagger", "武士短刃" );
        set_long("this is a short dagger with great power .\n",
            "这是一把锋利短小的匕首，虽然此匕首体积小但却含有其大的破坏力\n"
        );
        set( "unit", "把");
        set( "weapon_class", 27 );
        set( "type", "dagger" );
        set( "min_damage", 13 );
        set( "max_damage", 28 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
}


