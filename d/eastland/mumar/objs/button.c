#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "golden button", "金扣子" );
        add( "id", ({ "button" }) );
        set_short(  "金扣子" );
        set_long( @C_LONG
这是一颗纯金制的扣子，上面刻著一个『李』。
C_LONG
                );
                set("unit","颗");
                set("weight", 5);
                set("value",({1, "silver"}) );
        set("no_sale", 1 );
}
