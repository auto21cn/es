#include <mudlib.h>
 
inherit WEAPON;
 
void create()
{
        set_name("hammer", "铁□");
        set_short("铁□");
        set_long(
                "这把铁□是一般工匠用来修复装备用的工具。\n"
        );
        set( "unit", "把" );
        set( "weight", 80 );
        set( "type", "blunt" );
        set( "weapon_class", 6 );
        set( "min_damage", 4 );
        set( "max_damage", 11 );
        set( "value", ({ 30, "silver" }) );
}
