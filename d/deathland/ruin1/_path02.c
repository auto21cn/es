// File: /d/deathland/ruin1/path02.c
// Generated by Roommaker Thu Nov 23 20:52:13 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("黑黑的小径");
	ob->set_long( @LONG_DESCRIPTION
一条黑黑的小路 ,这小路的通道狭隘 ,你必须很费力地才能通过这里 .
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/ruin1/path03", 
		"west" : "/d/deathland/ruin1/path01" ]) );
	ob->reset();
}
