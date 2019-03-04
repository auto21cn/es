#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『咖哩咖哩牧场』的乳品收集厂");
    set_long(@LONG
这里是『咖哩咖哩牧场』的乳品收集厂，场内到处充斥著奇形怪状的仪
器；只有少量的半人马工人在这里工作，因为所有的控制都是魔族利用奥妙
的古魔法在控制著。因此当你进到这个工厂时，可以明显的感到有一股不可
思议的能源，正在你的周围不断的流动。
LONG
            );
    set("light",1);
    set("exits",(["north":CITY"pasture3"]) );
    set("objects",([
        "cow#2":TMOB"milker",
        "cow#1":TMOB"milker",
        "worker#2":TMOB"worker",
        "worker#1":TMOB"worker"]) );    
    reset();
#include <replace_room.h>
}
