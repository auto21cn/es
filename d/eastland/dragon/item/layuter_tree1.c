
#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name( "occult club", "神秘棍" );
        add( "id",({ "club" }) );
        set_short( "神秘棍" );
        set_long(
            "这是神秘树的中心精华，拥有举世无匹硬度。\n"
        );
        set("layuter_club",1);
        set( "unit", "棵");
        set( "weight", 400 );
        set( "value", ({ 0, "gold" }) );
}
