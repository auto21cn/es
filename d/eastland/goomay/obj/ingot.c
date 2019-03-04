#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("broken symbol","破损的金牌");
        add( "id" , ({ "symbol" }) );
        set_short("破损的金牌");
        set_long(@LONG
这是一块破旧的金牌，上面刻著弯弯曲曲的条纹，不知道是什麽东西，
看来能辨识它原来模样的只有经验丰富的当铺或是古董店老板了。
LONG
	);
        set("unit","块");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
