#include "../takeda.h"

inherit OBJECT;

void create()
{
       set_name("cook note","厨师笔记");
       add("id",({"note"}) );
       set_short("厨师笔记");
	   set_long(
           "这是一本有点发黄的笔记，记载著厨师的烹饪心得...\n"
	);
	
	set( "unit", "本" );
	set( "value", ({ 10, "silver" }) );
}
