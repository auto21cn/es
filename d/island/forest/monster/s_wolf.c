#include "../tsunami.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Little wolf","小野狼");
    add("id",({"wolf"}) );
    set_short("小野狼");
    set_long(@LONG
这是一只小野狼，仔细一看，还真是讨人喜欢呢！它看到你进来，似乎对你蛮感兴趣
的，不断的摇著尾巴，好像要你和它玩耍呢！
LONG
            );
    set("unit","只");
    set("alignment",-100);
    set("weight",100);            
    set_natural_weapon(5,5,10);
    set_natural_armor(10,5);
    set_c_verbs( ({"%s奋力扑向%s","%s努力咬向%s"}) );
    set_c_limbs( ({"头部","身体","屁股","尾巴"}) );
}