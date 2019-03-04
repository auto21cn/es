#include <irc.h>
#define BOARD "/d/std/IRC/irc_board"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Lobby","大厅" );
    set_long(
@LONG
You are in a square shaped, somewhat crude room. There are two
identical metallic doors to the north and east direction. The post
office is to the west. You can hear some noise coming from the south.
 
LONG
@C_LONG
这是一间陈设简单的方形大厅. 在北, 东两个方向各有一个完全相
同的金属门. 西边是邮局. 南方的房间隐约传来人声.
 
C_LONG
    );
    set("exits", ([
    "north"  : RM+"chatroom_1",
    "east"   : RM+"chatroom_3",
    "south"  : RM+"pub",
    "west"   : RM+"irc_post"
                ]) );
    BOARD->frog();
 
}
 
