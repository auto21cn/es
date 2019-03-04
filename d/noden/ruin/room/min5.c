// min5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿内厅");
    set_long(@C_LONG
你现在在神殿的内厅里，四周一片空空汤汤，只有素净的墙壁和天
花板静静地立著。凛冽的寒风由四面八方吹来，令你觉得有些寒冷。「
哪来的这麽大风？」你的心中不由得纳闷著。  
C_LONG
    );
    set("exits", ([
	"north" : AREA"min6",
	"south" : AREA"min4"
	]) );
    reset();
}

