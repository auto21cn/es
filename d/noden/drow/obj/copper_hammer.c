#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("copper hammer","铜角□");
   add("id",({"hammer"}));
   set_short("铜角□");
       set_long(
@C_LONG
这是把由铜片镶在原木块上的□子，握把的地方刻有蜘蛛的图案。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 15 );
        set("type","blunt");
        set( "min_damage", 14 );
        set( "max_damage", 20 );
        set( "weight", 80 );
        set( "value", ({ 280 , "silver" }) );
}
