
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鸟人祭坛");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
这里是鸟人族最重要的圣地，高高的矗立在天空之城的最顶点。你侧耳
倾听，听到一丝一丝诡异的声音从悬崖的深处往上飘啊飘。再往下一望，只
看到无穷无尽，淡淡的紫色雾气，虚无飘缈的感觉让你不禁有点脚软。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southwest" : HAWK"room3-7",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god" ]) );
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
