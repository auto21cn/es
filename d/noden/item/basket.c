#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "basket", "竹篮" );
   set_short( "竹篮" );
	set_c_open_long( "这是一个能装东西的竹篮，虽然编得颇为粗糙，但是看起来相当耐用。\n" );
	set("prevent_put_money",1);
	set( "weight", 20 );
	set( "max_load", 140 );
	set( "value", ({ 13, "silver" }) );
}
