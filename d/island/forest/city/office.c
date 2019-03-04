#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("将军府");
    set_long(@LONG
门口伫立著两只雄壮威武的石狮子，彷佛在提醒别人不可在此撒野。梁
上挂著写著『神武将军府』的横匾，原来这儿就是总管魔族军备的军部。受
封为神武将军的人可谓「一人之下，万人之上」，手握强大的兵权，连祭司
都得敬畏三分！
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway3"]) );
    set("objects",([
        "general":TMOB"general"]) );
    reset();
#include <replace_room.h>
}




