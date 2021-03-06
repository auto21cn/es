#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
        ::create();
        set_short("A empty room", "魔神商店");
        set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
你现在来到了魔神公会内部所附设的商店，这里卖的东西虽然不是顶好，不
过对於刚来到这个世界的魔神而言，一些基本装备总是有所帮助的，你可以翻阅
桌上的价目表(menu)，看看这里卖些什麽。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits",([
    "north" : "/u/b/boss/god/guild/god_guild.c",
    "up"  : "/u/b/boss/workroom.c",  
        ]) );
        set( "item_func", ([ 
                "menu" : "show_menu" ]) );
        set_inventory( ({
              ({ "/d/eastland/saulin_temple/obj/seed", 10,10 }),
                ({ "/d/eastland/liang_shan/obj/snow_lily", 10, 10 }),
        }) );
        reset();
}

void reset()
{
        room::reset();
        seller::reset();
}
