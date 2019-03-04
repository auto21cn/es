#include "../../story.h"
inherit MONSTER;
inherit "/std/seller";
void create()
{
    ::create();
    set_level(6);
    set_name( "vendor", "路边小贩" );
    set_short( "路边小贩" );
    set_long(@LONG
一个看起来很友善的小贩，如果你有需要的话，可以向他购买物品，只要问他价钱
(price)，他就会让你看他的货物。除此之外，这里还贩卖「巫咸国」的特产之一
－无底袋，保证让你满意。
LONG    
    );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set_inventory( ({
	({ "/obj/bandage", 20, 20 }),
        ({ SWITEM"bag1", 10, 5}), 
        ({ SWITEM"crystal1",45,10 }),
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

