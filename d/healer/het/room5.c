#include <mudlib.h>
#include "wang.h"

inherit ROOM;

void create()
{
	::create();
    	set_short("密室");
	set_long( 
		 @C_LONG_DESCRIPTION
这里是王药师的密室，看起来还蛮乾净的，好像常常有人出入。不过这里的
东西实在少的可怜，只有左手边有一张桌子，桌上放著一本有点旧的书。
C_LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"book" : @LONG_TEXT
这本书应该是王药师的笔记吧，藏个这麽秘密。你可以查看(read)这本书的
药方表(list)。
LONG_TEXT
 ]) );
    	set( "exits", ([ 
		"west" : WANG"room4" ]) );
	reset();
}

void init()
{
	add_action( "do_read", "read" );
}

int do_read( string str )
{
	int page;

	if( !str || str=="" ) return notify_fail( "阅读什麽？\n" );
	if( str=="list" ) {
		cat(POISON_INFO"c_list"); 
		return 1;
	} else if( sscanf(str, "page %d", page)==1 ) {
		if ( file_exists(POISON_INFO"c_page" + page) )
			cat( POISON_INFO"c_page" + page );
		else
			write("这页字迹模糊，你怎样用力也看不清楚\n");
		return 1;
	}
}
