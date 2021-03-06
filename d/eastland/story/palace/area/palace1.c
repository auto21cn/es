#include "../../story.h"

inherit SPALACE"RR";
inherit DOORS;
void create()
{
        ::create();
	set_short("天都大门");
	set_long( @LONG
你立足之地是天都的大门口，大门宽八尺高三丈，通体用美玉制成，巨门上纹
路变化万千，雕云缕月，把此地衬托的更加气象庄严。旁边一琼槛瑶阶，连接的是
一条白玉小路。东边是天都的大殿。
LONG
	);
	set("light",1);
        set( "exits", ([
            "down" : SPALACE"plain3",
            "east" : SPALACE"w1"
        ]) );
        set( "objects", ([
           "soldier1" : SPMOB"soldier1",
           "soldier2" : SPMOB"soldier1",
           "soldier3" : SPMOB"soldier1",
            "general" : SPMOB"soldier2",
        ]) );
        create_door( "east","west" ,([
             "keyword" : ({ "jade door", "door" }),
             "name" : "jade door",
             "c_name" : "玉门",
             "c_desc" : "一个白玉做的大门，上面各有两个碗大的雀环。\n",
             "status" : "closed"
        ]) );
	reset();
}
