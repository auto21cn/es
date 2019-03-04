#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小路" );
	set_long(@LONG
这是一条地图上找不到的小路，两旁长满了长长的芦苇，随风摇曳。	  
传说这儿常有翦径强人出没，他们会不会就躲在芦丛内呢? 你不禁多看
了看芦苇(weed)深处几眼
LONG
   );
        set("c_item_desc",(["weed":
"你仔细的看著这一大丛芦苇，一阵风来，你突然发现芦苇丛後似乎别有\n"            
"洞天，也许\你可以试著进去(pass)看看....\n"            
            ]));        
	set_outside("eastland",1);
        set( "exits", ([
                "north" : TROOM"out2",
                "south" : "/d/eastland/1,12.east"
        ]) );
        reset();
}
void init()
{
add_action("do_pass","pass");
}

int do_pass(string arg)
{
 if ( !arg || arg != "weed")
    return notify_fail("pass 什麽? 要 all pass 就快去念书吧 !\n");
 if ( present("mountain thief"))  
 	return notify_fail("山贼把你拦住，暧昧的看著你 ...\n");
    write ("你两手分开芦苇丛，一头钻了进去...\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "一头钻进了芦苇丛.....\n" ,
    this_player());
    this_player()->move_player(TROOM"lake/beach10","SNEAK");
return 1;
}
int clean_up() { return 0; }    