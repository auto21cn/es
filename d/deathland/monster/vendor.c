#include "../echobomber.h"

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "dwarf vendor", "矮人小贩" );
	set("id",({"vendor","dwarf"}));
	set_short( "a dwarf vendor", "矮人小贩" );
	set_long(
		"A dwarf vendor. You can buy something from him. Just\n"
		"ask him about \"item\", he'll tell you what you can buy.\n",
		"一个矮人小贩，你可以向他购买物品，只要问他物品(item)"
		",他就会让你看他的货物.\n"
	);
	set_perm_stat( "dex", 8 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 10);	
	set ("max_hp", 299);
	set ("hit_points", 299);
	set_natural_weapon( 18, 12, 15 );
	set_natural_armor( 55, 15 );
	set( "race", "dwarf" );
	set( "gender", "male" );
	// set( "no_attack", 1 );
	set_inventory( ({
		({ "/obj/torch", 20, 20 }),
		({ "/obj/bandage",10,10}),
		({ "/obj/bag",5,5}),
	}) );
	set( "inquiry", ([
		"item" : "@@show_menu"
	]) );
	set( "shop_name", "vendor" );
}

void init()
{
	npc::init();
	seller::init();
}