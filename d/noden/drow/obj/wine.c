#include <mudlib.h>

inherit POTION;

void create()
{
        potion::create();
        set_name( "wine","术酒");
        add( "id", ({ "wine" }) );
        set_short( "术酒");
        set_long(
@C_LONG
这是一罐由老村长所调制的术酒，闻起来有股浓郁的药味，可能
对於身体有病痛的人，具有不少的疗效吧。
C_LONG
        );
// so high ???
// set_healing(250);
   set_healing(100);
        set( "no_sale", 1 );
        set( "unit", "罐");
        set( "weight", 40 );
        set( "value", ({ 700, "silver" }) );
        set( "medication",10 );
        set( "effect_critical",10 );
}
