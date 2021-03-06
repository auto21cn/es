#include "island.h"

#define ROOM_OBJ "/d/island/7,2.island"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({  "noden", "/d/noden/6,6.noden", 60, 120 }),
	({  "eastland", "/d/eastland/18,10.east", 60, 120 })
                   });

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
//	set_name( "gate","遁甲之门" );
	set("name","gate");
	add( "id", ({ "gate" }) );
	set_short( "遁甲之门" );
	set_long(@LONG
这是传说中仙人用奇门遁甲之术，所造出的门，在西方就是所谓的传送
术，虽然说是门，但这是找不到特定名词才这麽说的，事实上它不过是
个闪著光芒的长方形框框，听说它会在不同的时间出现在不同地方，想
进去的话用进入(enter)试试看。
LONG
 );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

void init()
{
	add_action( "do_enter", "enter" );
}

int do_enter(string arg)
{
	if( !arg || !id(arg) ) 
	{
	write(@LONG
	
你要进入啥东东呀？

LONG
              );
	return 1;
	}
	else
	{
	write(@LONG
	
跨过遁甲之门，你到达另一个新的空间。

LONG

            );
	this_player()->move_player( ROOM_OBJ,
		"\n"+this_player()->query("c_name")+"进了遁甲之门。\n",
	        "\n"+this_player()->query("c_name")+"从遁甲之门进来了。\n" );
	return 1;
	}
}

void announce()
{
	int next_loc;
	object gate_room;

	next_loc = (loc+1)%sizeof(schedule);
	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	tell_room( environment(this_object()),"\n遁甲之门的形体渐渐模糊。\n\n" );
	call_out( "lets_go", 20 );
}

void lets_go()
{
	int next_loc;
	object gate_room;

	next_loc = (loc+1)%sizeof(schedule);
	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	tell_room( environment(this_object()), "\n周围的空间恢复原样，遁甲之门不见了。\n\n" );
	call_out( "arrive", schedule[loc][3] );
	ROOM_OBJ->set_location( "virtual" );
	loc = next_loc;
}

void arrive()
{
	object gate_room;

	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][1] );
	tell_room( environment(this_object()),"\n周围的空间开始扭曲，遁甲之门逐渐形成了\n\n" );
	call_out( "announce", schedule[loc][2]-20 );
}

