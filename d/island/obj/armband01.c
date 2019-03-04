#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("life armband", "悬命之巾");
        add( "id", ({"armband" }) );
        set_short("命悬之巾");
        set_long(@C_LONG
这是钱形次郎每次作案时专门绑在臂上的手巾，「一生悬命」其实就是钱形次郎的写照。        
C_LONG
        );
        set( "unit", "条");
        set( "type", "arms" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "material","cloth" );
        set( "weight", 20 );
        set( "value", ({ 500 , "silver" }) );
}
