// File: /open/polo/noden/farwind/cellar5.c
// Generated by Roommaker Mon Nov  6 06:28:40 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�ض�");
	ob->set_long( @LONG_DESCRIPTION
��ĵض��൱խС�����ߵĳ����ƺ���΢΢�����⡣������ŵ�һ�󸯳���
ζ���������ߡ�
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/noden/farwind/cellar6.c", 
		"west" : "/d/noden/farwind/cellar4.c" ]) );
	ob->set( "objects", ([ 
		"grey rat" : "/d/noden/farwind/monster/grey_rat" ]) );
	ob->reset();
}