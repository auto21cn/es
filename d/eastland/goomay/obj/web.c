#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name("Love web","柔丝情网");
        add( "id", ({ "cloak","web" }) );
        set_short("a Love web", "柔丝情网");
        set_long(
 "这是一件散发出晶莹光芒的披肩，就像是一面用世上所有少年男女对爱情
的美丽憧憬所编织成的网。 \n"
        );
        set("no_sell",1);
        set("unit","面");
        set( "type", "cloak" );
        set("material","element");
        set( "armor_class", 2 );
        set( "defense_bonus", 9 );
        set( "weight", 70 );
        
        set( "value", ({ 1400, "silver" }) );
}
