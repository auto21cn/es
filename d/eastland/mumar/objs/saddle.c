#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name( "golden saddle", "金色马鞍" );
        add( "id", ({ "saddle" }) );
        set_short( "金色马鞍" );
        set_long(
        "这是一副金色的皮革制马鞍，是牧马关骑兵威武的象徵。\n"
        );
        set( "type", "saddle" );
        set( "material", "leather" );
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 320, "silver" }) );
}
