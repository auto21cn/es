#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("archmaster's mark","令牌");
        set_short( "令牌");
        set_long(@C_LONG
一个玉做的小巧令牌，上面刻有「护国师　巫真」五个字，拥有这个令牌就可以自
由出入皇宫了。
C_LONG  );      
        set("unit","个");
        set("weight",10);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
