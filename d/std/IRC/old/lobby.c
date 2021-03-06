#include "irc.h"
#define BOARD "/d/std/IRC/irc_board"

inherit ROOM;

void create()
{
    ::create();
    set("light", 1);
    set_short( "Lobby","大厅" );
    set_long( @LONG
You are in a square shaped, somewhat crude room. There are
four identical archways to the north, west and east directions.
You can hear some noise coming from those.
LONG
	, @C_LONG
这是一间陈设简单的方形大厅。在南, 北, 东, 西四个方向各有一个
完全相同的拱门。各个房间均隐约传来人说话的声音。
C_LONG
    );
    set("exits", ([
    	"north"  : IRC"chatroom_1",
    	"east"   : IRC"deck_3",
    	"south"  : IRC"chatroom_4",
    	"west"   : IRC"chatroom_2",
    ]) );
    BOARD->frog();
}
