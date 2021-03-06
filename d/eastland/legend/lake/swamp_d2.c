#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼泽地底洞穴");
    set_long(@LONG
眼前忽然一亮，四下看去，原来是壁上长满了一种会发光的蕈类，叫做『曙薇』
，长的有巴掌大，发出萤光似的黄色光晕。只见一朵朵大大小小发光的蕈伞，就好像
灯火通明的不夜城一般。嗯，正当你看的入神之际，好像有些什麽东西正缓缓地移动
著，仔细一瞧，才发现，原来你四周有著许许多多的生物正在咬食『曙薇』。有趣的
事，所有的生物都是透明的，只有皮肤及关节的部份可以勉强辨识的出来。
LONG
    );
    set("light",1);
    set("exits",([
            "eastdown":LAKE"swamp_d4",
            "westup":LAKE"swamp_d1",
    ]) );
    set("objects",([
           "mollusk#1":LMONSTER"mollusk",
           "mollusk#2":LMONSTER"mollusk",
           "mollusk#3":LMONSTER"mollusk",
    ]) );
    ::reset();
}

