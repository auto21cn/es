#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("小茅屋");
	set_long( @LONG
一进到这里，你就发现满屋子里摆满了许许多多五花八门，琳朗满目的东西；
首先，在右边的柜子里分别摆满了壶、杯、瓶、盆和碗等容积类的东西，上面的漆
多是唐朝时代的；左边分别陈列了各式各样的武器，短刀乃至於长剑，通通都有，
每一件都隐隐有著异样的光芒；前面的几案上则是一些玉、如意、小动物之类；另
外有一竹篓盛满了卷轴、书籍和书法笔墨真贴。各式各样的东西令这里感到相当拥
挤。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "out" : SCITY"plain2"
        ]) );
        set("objects", ([
           "older":SWMOB"golden_older",
        ]) );
	reset();
}
