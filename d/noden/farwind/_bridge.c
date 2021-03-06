// File: /open/polo/noden/farwind/bridge.c
// Generated by Roommaker Mon Nov  6 06:27:33 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("石板桥上");
	ob->set_long( @LONG_DESCRIPTION
你现在站在一座石板桥上，桥下潺潺的流水声伴随著鹅群的叫声，与眼前
的景色构成一幅乡村田园的风景画。在你的东边是远风镇的西门，往西南走过
石板桥可以离开远风镇，西北边一条沿著河边的小路通往河流北岸的草原。
LONG_DESCRIPTION
	);

	ob->set_outside( "farwind" );
	ob->set( "exits", ([ 
		"northwest" : "/d/noden/13,5.noden", 
		"southwest" : "/d/noden/13,7.noden", 
		"east" : "/d/noden/farwind/w_gate" ]) );
	ob->reset();
}
