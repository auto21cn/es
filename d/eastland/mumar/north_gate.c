#include <mumar.h>
inherit ROOM;
 
void create()
{
 
        ::create();
        set_short("牧马关");
        set_long( @C_LONG_DESCRIPTION
这里是牧马关的北门，雄伟的建筑结构再次出现在你的眼前。向北出了关外就是
一片除了沙还是沙的黄色世界。历代的探险家和商人花费了几百年的时间才在这片茫
茫的翰海之中建立了丝绸之路，然而却有更多冒失的冒险家在那儿丢了性命。从这儿
往北就可以出关，往南不远则是教场。
C_LONG_DESCRIPTION
        );
        set( "light" ,1 );
        set( "exits", ([
                "south" : MUMAR "square05",
                "north" : MUMAR "north_gate"]) );
        set( "objects", ([
                "guard#1" : MOB "gate_guard",
                "guard#2" : MOB "gate_guard",
                 ]) );
 
        set("pre_exit_func",(["north":"go_north"]));
        reset();
}
 
int go_north()
{
        write("你试图向北走出城门，但一阵沙漠风暴把你吹了回来\n。");
        return 0;
}
