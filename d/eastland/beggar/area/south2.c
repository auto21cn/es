#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "south2", "『薪胆村』广场" );
	set_long(@C_LONG
这是一大片黄砂广场, 因为『丐帮』弟子常在此处练武功, 所以地面显得光
秃秃的一根杂草也没有。有时候风刮的很大挟带著漫天的灰尘, 尤其是每当南边
的高山吹著『落山风』, 真叫人眼睛睁不开。於是『丐帮』拟定做一些水土保持
的工作, 但是村里缺乏另一大片空地可以供弟子们练习, 所以每次提出做值地皮
的工作就会遭人反对, 於是乎人们还是得继续忍受下去。东、西、南和北边都是
广场的继续延申。
C_LONG
	);
	set_outside( "noden" );
	set( "exits", ([
                      "east":DBEGGAR"s2e1.c",
                      "west":DBEGGAR"s2w1.c",
                      "south":DBEGGAR"south3.c",
	              "north":DBEGGAR"south1.c"
	]) );
     reset();
}

