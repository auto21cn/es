// File: /d/noden/recamp/camp2.c
// Generated by Roommaker Sat Nov 25 14:15:48 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("小茅屋");
	ob->set_long( @LONG_DESCRIPTION
你现在来到一间简陋的小茅屋中，这间小茅屋搭得十分简陋，随时可能被
一阵强风吹垮，屋子里堆了不少木柴和乾草，这里显然是一间临时的储藏室或
仓库，你可以往西离开这间小茅屋。
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"west" : "/d/noden/recamp/camp1" ]) );
	ob->set( "objects", ([ 
		"boarman 2" : "/d/noden/recamp/npc/boarman" ]) );
	ob->reset();
}
