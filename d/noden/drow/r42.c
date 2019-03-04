
#include "iigima.h"

inherit "/d/noden/drow/in_water";
void create()
{
        ::create();
           set_short("阴暗水池");
        set_long(
@LONG
这里灰暗潮湿，积水约半公尺深，你闻到一股恼人的霉味，与
水流悉娑的声音，你看到石墙上仍有蛇蜕下的皮黏挂在那儿，可见得
这里还是有生物的。你往身旁一看，看到一副浸泡在水里多年的骷髅
，旁边还放了小偷最爱用的万用小刀一把，看来是哪个倒楣的小偷以
前挂在这里吧，四处找找，说不定可以找到他留下来的宝物唷。
LONG
        );
        set( "exits", ([
           "up":DROW"r29",
        ]) );
        set("objects", ([
             "mad snake": DRO"s7",
        ]) );
        set("pre_exit_func",(["west":"check_snake"]));
        reset();
}
int check_snake()
{
     if(present("mad snake",this_object())){
       write("猛暴海蛇迅速窜动，令你难以行动！\n");
       return 1;}
       return 0;
}
