#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(7);
        set_name("soldier","青年士兵" );
        add ("id", ({ "soldier","young"}) );
        set_short( "young soidier","青年士兵");
        set("unit","位");
        set_long(@ANGEL
这是一个武士团中地位最低的士兵，是个刚刚被徵招入伍的新兵
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/silver",50);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(MOBJ"iron_blade.c");
}