
#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "merchant","杂货商人" );
        add ("id", ({ "merchant"}) );
        set_short( "merchant","杂货商人");
        set("unit","位");
        set_long(@ANGEL
这是一个杂货的商人
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
}