#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(3);
    set_name("Big Snake","大蟒蛇");
    add("id",({"snake"}) );
    set_short("大蟒蛇");
    set_long(@LONG
一尾颇吓人的大蟒蛇正盘踞在山洞旁的树枝上，发现你的到来，正
不断的对著你吐著蛇信，好像在侦查你似的!!
LONG
    );
    set("unit","尾");
    set("no_attack",1);
}