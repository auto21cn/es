#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("私塾");
	set_long( @LONG
这里是「巫咸城」里人民学习知识的地方。私塾里除了桌椅之外，四周墙壁上
还挂有几张泼墨山水画和几贴真迹。不但学子们正聚精会神地□听教诲，教师更认
真地传授众人的知识。在空气中，「子曰子曰」的朗诵声音此起彼落，课堂里端得
是严肃无嚣的气氛。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "north" : SCITY"nw2"
        ]) );
        set("objects", ([
             "teacher":SWMOB"teacher1",
           "student#1":SWMOB"student1",
           "teacher#2":SWMOB"student1",
           "teacher#3":SWMOB"student1",
        ]) );
	reset();
}
