#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮灵族部落");
	set_long( 
@LONG_DESCRIPTION
这里是矮灵族部落群，西边可以通到出口，东边可通到广场，这里的建筑物大都
是石造的，少数人住帐蓬，地上用很多石板铺成的路贯穿整个部落，整个部落给人的
感觉是非常宁静且安详的，你注意到旁边有一个挂满人头的柱子，当风吹过时，人头
嘎嘎作响，令人毛股悚然。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "west" : OGROUP"warea1",
     "southeast" : OGROUP"warea4",
     "northeast" : OGROUP"warea6" ]) );
set( "search_desc",([
     "here":"@@to_search_here",
     ]) );
set_outside("eastland");
reset();
}

string to_search_here()
{
  return  "\n你见到路旁的一根石柱，柱子上有著许\多的小洞，几乎每个小洞都被一条绳子穿过，\n而绳子的另一端，则悬著一颗骷\髅头。\n\n";
}
