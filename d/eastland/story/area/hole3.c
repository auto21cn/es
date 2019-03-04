#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
你来到了一处黑暗的洞穴，这里空洞洞地似乎没有任何东西。除此之外，你感
到这里非常潮□，空气中还有些发霉的味道，让你混身感到不舒服。在这里，不时
听到些动物的嘶吼声，其声可怖已极，更兼在地上看到一堆骸骨，说明了这实在不
是个安全的地方。西边是禁地，据说，需要具备经过天神祝福的铠甲才能安全无虞
地通过。
LONG
	);
        set( "exit_suppress", ({
           "nd"}) );
                  
	set("exits", ([
          "east" : SAREA"hole1",
          "west" : SAREA"spell1"
        ]) );
	reset();
}
