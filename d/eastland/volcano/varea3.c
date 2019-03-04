#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("山腰");
	set_long( 
@LONG_DESCRIPTION
那耸立云霄的火山山口似忽还会有阵阵浓烟冒出，不知何时还会再爆发，你觉的
这里非常的热，不可能有生物能在这里生存下去，这里到处都是火山岩和浮石。你站
在山腰处，往上望去，心里想著要到达火山顶还一大段距离，休息一下吧，这座由火
山岩所构成的火山，由於到处是巨大的裂缝，因此想到达山顶是相当困难的。
LONG_DESCRIPTION
	);

set( "exits", ([
     "south": ONEW"varea2",
     "southeast" : ONEW"varea5" ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_climb","climb");
}

int do_climb()
{  if( random( (int)this_player()->query_skill("climbing") ) < 50 ) {
      write( 
         "想爬上去，门儿都没有!\n");
      return 1;
    };
    write( 
          "你使出吃奶的力气终於爬了上去。\n");
    this_player()->move_player( ONEW"varea6.c","SNEAK" );
    return 1;
}

