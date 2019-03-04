// g10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("废弃的花园");
    set_long(@C_LONG
你来到了一个废弃的花园，到处长满了杂草和青苔。这里的空气充满著肃
杀的气氛，似乎连你身上的血液也快要为之凝结起来。杂草上沾满了斑斑血迹
，看来这儿曾死过不少人。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"g10",
	"east" : AREA"g9",
	"west" : AREA"g3",
	]) );
    set("objects", (["deathknight" : MOB"deathknight"]));
    reset();
}


	    
