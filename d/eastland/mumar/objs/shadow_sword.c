#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "shadow sword", "影剑" );
        add( "id", ({ "sword" }) );
        set_short( "影剑" );
        set_long(
                "这是一把暗赤色的长剑，凹凸不平的剑身似有点点斑影，故名。\n" );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 120 );
        set( "weapon_class", 23 );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "value", ({ 500, "silver" }) );
}
