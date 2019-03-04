#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "huge hammer", "大□头" );
        add( "id", ({ "hammer" }) );
        set_short("大□头");
        set_long(
                "这是一支和树干差不多大只的大□头，看来相当沉重。\n"
        );
        set( "unit", "支" );
        setup_weapon( "blunt", 25, 11, 28 );
        set( "weight", 300 );
        set( "value", ({ 50, "silver" }) );
}
