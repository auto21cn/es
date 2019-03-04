
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult tree", "神秘树" );
        add( "id",({ "tree", "layuter_tree" }) );
        set_short( "神秘树" );
        set_long(
            "这是一棵会随著时光的转换，以五行之术移动的树。\n"
        );
        set( "unit", "棵");
        set( "weight", 18000 );
        set( "value", ({ 0, "gold" }) );
}
