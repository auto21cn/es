#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿内长廊");
	set_long( @LONG
殿内长廊到这里已经是尽头，廊道往东南方向延伸。廊道白玉铺地，栏杆雕饰
精细，朱壁每尺镶嵌著拳大夜明珠，流莹生辉，照耀著满道通明。廊旁有几座楼阁
，每座竟不知好几层，每层九间，通体碧玉砌成，琼槛瑶阶，金门翠东，雕云缕月
，气象庄严，奇丽无俦。细看前面几层，层层的陈设无不穷极精丽，妙夺天工，於
珠光宝气中现出古色古香，别有雍穆清雅之致。楼阁之中围著一小型殿堂，玉柱金
庭，珠光宝气。
LONG
	);
        set("light",1);
        set("exits" , ([
           "southeast" : SPALACE"s2",
           "southwest" : SPALACE"house3",           
        ]) );
        set("pre_exit_func",([
            "southwest":"can_pass"]));
        reset();
}        
int can_pass()
{
        if ( this_player()->query("palace_war") ) return 1;
        return 0;
}