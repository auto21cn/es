#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "break jade", "碎玉佩" );
        add( "id", ({ "jade" }) );
        set_short( "碎玉佩" );
        set_long( @C_LONG
这是一块上好的翠玉，不过似乎并不是完整的一整块。上面用篆字刻著一个『罪』字。
C_LONG
                );
        set("unit","块");
        set("weight", 10);
        set("sky_guilt_jade2",1);
        set("value",({10, "silver"}) );
        set("no_sale", 1 );
}
