// File: /d/eastland/7,18.east.c
// Generated by Roommaker Wed Nov 22 13:17:24 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("龙穴入口");
	ob->set_long( @LONG_DESCRIPTION
在你的眼前是一面高耸的山壁，有一个巨大的山洞在其左侧，当你走到此处时，
你发现往山洞望去是无边的黑暗，你想这应该是一个相当深隧的山洞，并且由山洞中
传来阵阵的阴风中带有浓厚的腥风，令人闻之欲睡，你想其中也许\有前古猛兽居住其
中。
LONG_DESCRIPTION
	);

	ob->set_outside( "dragoncave" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"cave" : "/d/eastland/dragon/cave2", 
		"east" : "/d/eastland/8,18.east", 
		"north" : "/d/eastland/7,17.east" ]) );
	ob->reset();
}
