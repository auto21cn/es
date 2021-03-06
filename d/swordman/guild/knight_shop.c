#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "骑士商店");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你现在来到了骑士公会内部所附设的商店，这里卖的东西虽然不是顶好，不
过对於刚来到这个世界的骑士而言，一些基本装备总是有所帮助的，你可以翻阅\
桌上的价目表(menu)，看看这里卖些什麽。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/knight/fortress/knight_inner" ]) );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set_inventory( ({
		({ "/d/knight/fortress/weapons/battleaxe", 3, 3 }),
		({ "/d/knight/fortress/weapons/waraxe", 5, 5 }),
		({ "/d/knight/fortress/weapons/longsword", 10, 10 }),
		({ "/d/knight/fortress/weapons/shortsword", 15, 15 }),
		({ "/d/knight/fortress/armors/chainmail", 10, 10 }),
		({ "/d/knight/fortress/armors/shield", 10, 10 }),
	}) );
	reset();
}

void reset()
{
	room::reset();
	seller::reset();
}