
#include <mudlib.h>

inherit OBJECT;
void create()
{
	seteuid(getuid());
        set_name("pearl", "幻魔珠");
        add( "id", ({ "pearl","daemon pearl" }) );
        set_short( "幻魔珠" );
        set("long",@LONG
这是撒巴吐卡用塔姆姆秘术所制造出来的宝珠，据说有降伏魔物的神奇力量。
LONG
        );
        set( "weight", 5 );
        set( "unit", "颗" );
}

void init()
{
        add_action("to_say","say");
}

int to_say(string s)
{
        if (s != "ern!-sdl") return 0;

        if ( (this_player()->query_temp("smore_armor/arcold") != 1 )
          || (this_player()->query_temp("smore_armor/elder") != 1)
          || (this_player()->query_temp("smore_armor/knight") != 1)
          || (this_player()->query_temp("smore_armor/minister") != 1)
          || (this_player()->query_temp("smore_armor/las") != 1) )
                return 0;

        tell_object(this_player(),@LONG
你手中的宝珠发出一道光芒照在食肉兽的身上。

你可以赶快企图去控制(control)它
LONG
        );
        this_player()->set_temp("control_flesh",1);
	this_object()->remove();
        return 1;
}
