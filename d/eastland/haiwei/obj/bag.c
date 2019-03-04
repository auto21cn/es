#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("miscellaneous bag", "八宝袋");
	add( "id", ({ "bag" }) );
	set_short("八宝袋");
	set_c_open_long("这个八宝袋可以用来装不少东西。\n");
	set("weight", 10);
	set("weight_apply", 50 );
	set("max_load", 250);
	set("value", ({ 540, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
