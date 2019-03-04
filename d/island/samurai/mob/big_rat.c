#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(7);
        set_name( "big rat","大老鼠" );
        add ("id", ({ "rat"}) );
        set_short( "big rat","大老鼠");
        set("unit","只");
        set_long(@ANGEL
这是一个大老鼠，看起来很凶恶的样子
ANGEL
        );
        
        set ("gender", "male");
        set_c_verbs(({"%s用它锐利爪子抓向%s","%s身体一转用尾巴甩向%s","%s跳来用牙齿咬向%s"}));
        set_c_limbs(({"身体","头部","脚部","尾巴"}));
}