#include <mudlib.h>

inherit WEAPON;
void create()
{
   set_name("shortsword","小短刀");
   add("id",({"sword"}) );
   set_short("小短刀");
       set_long(
@C_LONG
    小而钝的小刀子。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 6 );
    set("type","shortblade");
        set( "min_damage", 2 );
        set( "max_damage", 6 );
        set( "weight", 20 );
        set( "value", ({ 40 , "silver" }) );
}
// Ending QC.
