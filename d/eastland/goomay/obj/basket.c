#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("basket", "菜篮");
	set_short("菜篮");
	set_c_open_long("这是一个买菜用的篮子，可以装东西。\n");
	set("weight", 50);
	set("weight_apply", 80 );
	set("max_load", 150);
	set("value", ({ 40, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
