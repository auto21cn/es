#include <mudlib.h>

inherit MONSTER;
inherit "/std/seller";
void create()
{
    ::create();
    set_level(6);
    set_name( "travel merchant", "旅行商人" );
    add( "id",({"merchant"}) );
    set_short( "旅行商人" );
    set_long(@LONG
一个从东方大陆来的商人，正在空地上休息。他平时喜欢到处旅行，结交一些英雄
好汉，顺便做做生意。他卖的东西都是不二价，东西也不偷工减料，所以，很多人
都会来跟他买东西，你可以问问他价钱 ( price ) 看是否有什麽需要的。
LONG
    );
    set( "race", "human" );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set_inventory( ({
          ({ "/obj/bandage",10,10 }),
          ({ "/d/eastland/easta/obj/spicy_plaster", 10, 20 }),
          ({ "/d/eastland/easta/obj/green_pill", 10, 20 }),
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