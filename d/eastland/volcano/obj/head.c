#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "head", "人头" );
	set_short( "人头" );
	set_long(
		"这是一个冒险者的头。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "个" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
        call_out("disappear",300,this_object());
}

void disappear(object ob)
{
  object owner;
  owner=environment(this_object());
  if (!owner)
    printf("这割下来的人头因时间而风化掉了。\n"); 
  remove(); 
}
