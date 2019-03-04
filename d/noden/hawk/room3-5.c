
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鸟人祭坛");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
这里是鸟人族最重要的圣地，高高的矗立在天空之城的最顶点。你往下
一望，只看到无穷无尽的黑雾，诡异的散发出来，阴气森森，杀气腾腾的感
觉让你不禁有点脚软。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northeast" : HAWK"room3-3",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god1" ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_jump","jump");
}

int to_jump()
{
        this_player()->receive_damage(120);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        return 1;
}
