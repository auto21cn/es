// File: /d/noden/elf/elf/elf16.c
// Generated by Roommaker Mon Dec  4 21:44:53 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("精灵屋");
	ob->set_long( @LONG_DESCRIPTION
这里是精灵小屋在屋子的北方有一张用杉木制成的书桌，
及一张用石头做的椅子，西边是一面挂满图画南面有一张铺著
绣有精灵族图案被子的床，而在空气中传来一股似有似无的香
味，使你精神一振。

LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/noden/elf/elf/elf11" ]) );
	ob->set( "objects", ([ 
		"lady" : "/d/noden/elf/monster/lady" ]) );
	ob->reset();
}
