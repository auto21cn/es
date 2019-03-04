#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼泽地底洞穴");
    set_long(@LONG
这里已经是在地下超过三十丈深的地方，墙壁上的『曙薇』明显少了许多，不过
有更多奇奇怪怪，连名字也叫不出植物参差和『曙薇』长在一起。有些跟『曙薇』一
样发出淡淡的萤光，有蓝，橙等颜色的；有些开著小小的花朵散著馥郁的芳香。正前
方小红花丛中一只无可明状的透明生物传来『嘤』、『嘤』的细微声响，好像在对你
示好一般。
LONG
    );
    set("light",1);
    set("exits",([
            "westup":LAKE"swamp_d2",
    ]) );
    set("objects",([
      "shapeshifter":LMONSTER"shapeshifter1"
    ]) );  
    ::reset();
}

