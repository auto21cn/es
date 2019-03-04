
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("potion", "奇怪的药水");
        add( "id", ({ "s_potion","potion","strange potion" }) );
        set_short( "奇怪的药水" );
        set("long",@LONG
这是一个很奇怪的药水瓶，里面装了些橙色的药水，上面还贴了张标签(list)。
LONG
        );
        set( "weight", 20 );
        set( "unit", "瓶" );
}

void init()
{
        add_action("to_read","read");
}

int to_read(string s)
{
        if (s != "list") return 0;
        tell_object(this_player(),@LONG

你仔细的开始读上面所写的标签：
        成份：曼陀罗花的根，龙葵，百叶草，桐木果。
        作用：强化肌肉及神经反应。
请小心收藏，切勿外传。
LONG
        );
        return 1;
}
