#include "goomay.h"
inherit DOORS;
inherit ROOM;
int move;

void create()
{
        ::create();
        set( "move", 0);
        move = 0;
        set_short("牢房" );
        set_long(
@LONG
这里是捕快们关犯人的地方，犯了案的犯人都关在这里，简简单单的
牢房里只有一张稻草铺成的床，牢房中充斥著霉腐与死亡的气息，。这里
黑黝黝的，空气又差，你真想赶快出去。
LONG
        );
        
        set( "exits", ([ 
		"north" : Goomay"jail",
        ]) );
        set( "objects", ([
                "prisoner1" : Mob"prisoner1",
                "prisoner2" : Mob"prisoner1",
        ]) );
        set( "c_item_desc", ([  "bed" : "@@msg_bed",
                                "hole"  : "@@msg_hole",  ]) );
      create_door("north","south",
            ([  "keyword" : ({"door"}),
                "name"    : "Iron door",
                "c_name"  : "铁栅门",
                "c_desc"  : "这是一扇有著粗大铁栏的铁栅门",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );
        
        reset();
}

void init()
{
    add_action("to_move_bed", "move");
    add_action("to_enter_hole", "enter");
}

string msg_hole()
{
    if( !move )
      return ("你想看什麽？\n");

    return ( 
      "里面乌漆麻黑的，不知道会有甚麽，也\许\你可以进去试试看。\n");
}
string msg_bed()
{
    if( !move )
      return ("一张稻草床。\n");

    return (
      "一张稻草床，现在被搬离原来的地方，而露出一个洞。\n");

}

int to_move_bed( string arg )
{
    string dir;
    if( !arg )
      return notify_fail("move what ?.\n");
    if( arg=="bed" ) {
	if (!move)
	{
        write(
          "你把稻草床向旁一推，轻易的就把它推开，露出一个黑黝黝的洞。\n");
        move = 1;
        set( "move", 1);
		return 1;
	}
      else 
	{
        write(
          "你把稻草床推回原位。\n");
        move = 0;
        set( "move", 0);
		return 1;
	}
      return 1;
    }
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" || !move )
      return notify_fail("Enter what?\n");
    if( move )
      this_player()->move_player(Goomay"tunnel1.c","SNEAK");
    return 1;
}

void reset()
{
    ::reset();
    set( "move", 0);
    move = 0;
}
