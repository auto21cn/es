// File: /d/noden/elf/elf/elf5.c
// Generated by Roommaker Mon Dec  4 21:59:12 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("石板路");
	ob->set_long( @LONG_DESCRIPTION
这是一条用石板铺成的路，路的两旁是精灵屋及绿意盎然的植道树
，石板上刻著精灵族的标帜(mark)，很有规律地向前延伸。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/elf/elf/elf2.c", 
		"south" : "/d/noden/elf/elf/elf8.c", 
		"north" : "/d/noden/elf/elf/elf7.c", 
		"west" : "/d/noden/elf/elf/elf11.c" ]) );
	ob->set( "item_desc", ([ 
		"mark" : "这标志是一个带著桂花冠的天马\n" ]) );
	ob->reset();
}
