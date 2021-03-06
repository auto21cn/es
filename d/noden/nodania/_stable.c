// File: /d/noden/nodania/stable.c
// Generated by Roommaker Mon Dec  4 20:11:54 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("马房");
	ob->set_long( @LONG_DESCRIPTION
你现在来到了国王的马房，这里打扫得相当乾净，负责照顾国王战马的
马童对他的工作十分引以荣，从这里你可以望见西边的跑马场，往南是一条
石板铺成的小径。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/noden/nodania/w_path2" ]) );
	ob->set( "objects", ([ 
		"horse#3" : "/d/noden/nodania/monster/white_horse", 
		"horse#2" : "/d/noden/nodania/monster/brown_horse", 
		"horse#1" : "/d/noden/nodania/monster/brown_horse" ]) );
	ob->reset();
}
