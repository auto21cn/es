#include <mudlib.h>
#include "academy.h"

inherit ROOM;

void create()
{
	::create();
    set( "max_laod", 100000 );
	set( "light", 1 );    	
	set_short( "Academy of Wizards", "巫师学院" );
	set_long( @LONG
It needs work here.	
LONG
, @C_LONG
你现在正站在巫师学院的大门, 年轻的实习巫师们在这里学习如何将
他们们的构想实现出来, 同时也接受学校中的种种考验。在他们通过学校
中所有的考验的同时, 他们就拥有成为正式巫师的资格。
C_LONG
	);
	set( "exits", ([
		"north"  : HERE"hall"
	]) );
}
