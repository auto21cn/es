// File: /d/noden/nodania/e_path.c
// Generated by Roommaker Mon Dec  4 20:01:58 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("石板小径");
	ob->set_long( @LONG_DESCRIPTION
你现在走在一条石板铺成的小径，两旁生著疏疏落落的灌木丛。西
边是王宫前庭，小径向东延伸。
LONG_DESCRIPTION
	);

	ob->set_outside( "nodania" );
	ob->set( "exits", ([ 
		"east" : "/d/noden/nodania/e_path2", 
		"west" : "/d/noden/nodania/courtyard" ]) );
	ob->reset();
}
