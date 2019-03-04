#include <mudlib.h>

inherit "/std/seller";
inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "小贩" );
	set_short( "小贩" );
	set_long(@C_LONG
一个看起来很友善的小贩，如果你有需要的话，可以向他购买物品，只要
问他价钱(price)，他就会让你看他的货物。
C_LONG
	);
	set( "race", "halfling" );
	set( "gender", "male" );
	set( "no_attack", 1 );
	set( "shop_name", "vendor");
	set_inventory( ({
		({ "/obj/torch", 10, 10 }),
		({ "/obj/bandage", 10, 10 }),
		({ "/d/noden/farwind/items/pocket_map", 10, 10 })
	}) );
	set( "inquiry", ([
		"price" : "@@show_menu"
	]) );
}
