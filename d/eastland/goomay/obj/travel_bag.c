#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("traveller's bag", "旅行袋");
	add( "id", ({ "bag" }) );
	set_short("旅行袋");
	set_c_open_long("这是一种大型的旅行袋，可以装下不少东西。\n");
	set("weight", 30);
	set("weight_apply", 50 );
	set("max_load", 350);
	set("value", ({ 740, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
