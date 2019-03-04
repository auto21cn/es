#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("shadow bag", "幻影袋");
	add( "id", ({ "bag" }) );
	set_short("幻影袋");
	set_c_open_long("这是一个幻影袋 .当你打开它想要看清它的容量时 ,你发现里面是一团漆黑,\n"
	                "深不见底.\n"
	                );
	set("weight", 15);
	set("weight_apply", 40 );
	set("max_load", 300);
	set("value", ({ 1500, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
