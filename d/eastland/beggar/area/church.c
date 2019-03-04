#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "church", "祠堂" );
	set_long(@C_LONG
这是一间老旧的祠堂,因为年老未修缉, 所以看起来好像要□塌的样子。一眼
看过去桌上有很多架子,架上供奉的多是历代帮主和一些精忠报国之士的神主牌 。
檀香袅袅,诵经之声不断,顿时让你想詹仰先人的风范, 因而不禁严肃了起来,或许
是忠义心人人有之使得你有所感触吧。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "out":DBEGGAR"east7.c"
	]) );
        set( "objects", ([
                      "old":DMONSTER"old_garden.c",
                "enforcer1":DMONSTER"enforcer.c",
        ]) );
     reset();
}
