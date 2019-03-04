#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "洗衣房" );
	set_long(
	"这里是梁山泊的洗衣房，目前的大王宋江，认为寨内不可有人\n"
	"不事生产．因此，寨内一部份的妇女，在此清洗所有的衣物．角落\n"
	"有一口水井(well)．\n"
	  
	);
	set( "light",1 );
        set("c_item_desc",(["well":
"根据你多年来的直觉，你认为一定可以爬下去，而且下面一定有青蛙．\n"
            ]));        
        set( "objects", ([
             "boss" : TMONSTER"pang",
             "lady1" : "/d/eastland/goomay/monster/poor_woman",
             "lady2" : "/d/eastland/goomay/monster/poor_woman"
             ]));
        set( "exits", ([
                "north" : TROOM"path3",
                "south" : TROOM"dryroom"
        ]) );
        reset();
}
int clean_up() { return 0; }
/*
void init()
{
     add_action("do_climb","climb");
}
int do_climb(string arg)
{
if (!arg || arg !="well")
return notify_fail(
"爬什麽\n");
write (
"还没做好...:)\n");
} 
*/    