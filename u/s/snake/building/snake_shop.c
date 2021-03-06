#include <mudlib.h>

inherit ROOM;
inherit SELLER;

void create()
{       
        ::create();
        set_short("shop", "药店");
        set_long( " no describe\n",
        "这是一间药店！里面乌灯黑火的看不见一个人！只隐约看见墙边有一个人影。\n"
        "这里有一样行医者必备的器具, 你可以参考挂在墙上的目录(menu)。\n"
        );
        
        set("objects", ([
            "jack" : "/d/healer/building/monsters/jack"
        ]) );
        set( "light", 1 );
        set( "item_func", (["menu" : "show_menu"]) );
        set_inventory( ({
                ({"/d/healer/building/weapons/scalpel",5,5}),
        }) );
        reset();
}

void reset()
{
     room::reset();
     seller::reset();
     return;
}

int do_buy(string arg)
{
    if (this_player()->query("class") != "healer")
        return notify_fail("对不起，这里只做医生的生意，您请回吧!\n");
    return ::do_buy(arg);
}
