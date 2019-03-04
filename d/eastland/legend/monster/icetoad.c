#include <mudlib.h>

inherit MONSTER;

void create ()
{
       ::create();
       set_level(14);
       set_name( "ice toad", "冰蟾蜍");
       add ("id", ({ "toad" }) );
       set_short( "冰蟾蜍");
       set("unit","只");
       set_long(@LONG
    一只只有指头大小的蟾蜍。透明的身体外有一条条鲜红色的细纹，看起来相当的
□丽。
LONG    );
       set_skill("dodge",100);
       set_natural_weapon(35,10,12);
       set_natural_armor(60,15);
       set_c_verbs(({
         "%s吐出它的舌头向%s卷了过来",
         "%s向%s扑了过来",
         "%s高高的跳起然後撞向%s",
         "%s咕哇一声怪叫，射出一股烟雾罩向%s",
         }));
       set_c_limbs(({"腹部","头部","腿部"}));
}
