#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
	set_short( "漩涡" );
	set_long(@C_LONG
这里是巨大漩涡的底部，抬头望去，扭曲的水流仍然声势惊人，使人心惊肉跳。
你感到仍然隐隐有股吸力，将你往上拉去，你感到脚底虚浮，心底想著最好还是
赶快离开此处。
C_LONG
	);
	set( "exits", ([
             "north" : TROOM"underwater5",            
	     "west" : TROOM"underwater6",
	     "south" : TROOM"underwater7"
	]) );
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



