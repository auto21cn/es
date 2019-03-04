#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "wooden blade", "木刀" );
        add( "id", ({ "blade" }) );
        set_short("木刀");
        set_long(
                "这是一支牧马关新兵训练用的木刀。\n"
        );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weapon_class", 8 );
        set( "min_damage", 4 );
        set( "max_damage", 8 );
        set( "weight", 60 );
        set( "value", ({ 80, "silver" }) );
}
