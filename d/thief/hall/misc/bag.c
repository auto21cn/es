#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("bag", "麻布袋");
	set_short("a bag", "麻布袋");
	set_c_open_long("这个麻布袋是小偷常用来装赃物的袋子。\n");
	set( "weight", 20);
	set( "weight_apply", 50 );
   set( "max_load", 230 );
	set( "value", ({ 120, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}

