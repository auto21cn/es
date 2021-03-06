#include "../../story.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("药店");
	set_long( @C_LONG
你一走进这家药店就闻到一股刺鼻的药草味。这里是「巫咸城」里唯一的一家
合法药店，专门做些药物买卖交易的工作。这里所卖的东西不贵，也没有人会去讨
价还价的，所有的东西则全写在一张挂在壁上的单子(menu)，你可以看看它并且买
所需要的东西。
C_LONG
	);
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"west":SCITY"ws"
		       ]) );
	
	set( "objects", ([
	       "doctor":SWMOB"wiz_doctor1",
            "patient#1":SWMOB"patient1", 
            "patient#2":SWMOB"patient1",
            "patient#3":SWMOB"patient1",
	]) );
	set_inventory( ({
		({ "/obj/bandage",60,20 }),
		({ "/d/noden/farwind/items/white_plaster", 40, 20 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 30, 20 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 30 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 20 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 15 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}
