#include <mudlib.h>

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "卖药郎中" );
	set_short( "卖药郎中" );
	set_long(@C_LONG
你看到一个看起来落魄潦倒的中年人，他正拉著你想要推销他药囊中的
膏药，如果你有兴趣的话，问他有关 price 即可。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "int", 12 );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "kar", 9 );
	set_skill( "dodge", 40 );
	set_skill( "anatomlogy", 40 );
	set_temp( "aiming_loc", "ganglion" );
	set_natural_weapon( 10, 3, 6 );
	set( "wealth/silver", 100 );
	set( "shop_name", "vendor" );
	set_inventory( ({
		({ "/d/eastland/easta/obj/plaster", 20, 20 }),
		({ "/d/eastland/easta/obj/smelly_plaster", 30, 30 }),
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