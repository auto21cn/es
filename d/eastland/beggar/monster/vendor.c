#include <mudlib.h>


inherit MONSTER;
inherit "/std/seller";
void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "摊贩" );
	set_short( "摊贩" );
	set_long(
		"一个看起来很友善的摊贩，如果你有需要的话，可以向他购买物品，只要\n"
		"问他价钱(price)，他就会让你看他的货物。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "no_attack", 1 );
	set_inventory( ({
		({ "/obj/torch", 10, 10 }),
		({ "/obj/bandage", 10, 10 }),
		({ "/d/noden/farwind/items/pocket_map", 10, 10 }),
                ({ "/d/eastland/beggar/item/bag", 3, 3}), 
                ({ "/d/eastland/beggar/item/sausage", 10 , 10 }) 
   	}) );
	set( "inquiry", ([
		"price" : "@@show_menu"
	]) );
}
void init()
{
	npc::init();
	seller::init();
}

