// File: /open/polo/noden/farwind/riverbend.c
// Generated by Roommaker Mon Nov  6 06:29:27 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("河边空地");
	ob->set_long( @LONG_DESCRIPTION
这里是河边的一块空地，在你北边的桥底下是一个养鹅场，养鹅的人用
围篱围出一小片空地关住鹅群，但是你发现围篱似乎有破洞，因为你现在所
站的地方地上就掉了几根鹅毛(feather)，还有一些鹅的脚印。
LONG_DESCRIPTION
	);

	ob->set_outside( "farwind" );
	ob->set( "exits", ([ 
		"south" : "/d/noden/farwind/steps" ]) );
	ob->set( "objects", ([ 
		"goose 3" : "/d/noden/farwind/monster/goose" ]) );
	ob->reset();
}
