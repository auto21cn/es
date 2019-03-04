
#include "../echobomber.h"

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "shadow merchant", "幻影商人" );
	add("id",({"merchant",}));
	set_short( "a moorth merchant", "幻影商人" );
	set_long(
		"一个很奇怪的商人 ,全身上下好像是透明的样子 .似乎他已经死去很久了 ,但是他的\n"
		"灵魂却还在此地做他生前的工作 ."
	);
	set("alignment",-300);
//	set ("max_hp", 320);
//	set ("max_sp", 0);
	set_natural_weapon(40,18,40);
	set_natural_armor(55,10);
//	set ("hit_points", 320);
//	set ("spell_points", 0);
	set( "gender", "male" );
	set( "no_attack", 1 );
//	set("shop_name", "vendor");
	set_inventory( ({
		({ Object"/bag01", 1, 1 }),
	}) );
  	set( "inquiry", ([
		"item" : "@@show_menu"
	]) );
}

void init()
{
	seller::init();
	npc::init();
}