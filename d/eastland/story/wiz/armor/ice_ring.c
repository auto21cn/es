#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("ice-ghost ring","雪魂凝指");
        add( "id", ({ "ring" }) );
        set_short("雪魂凝指");
        set_long(@C_LONG
一只千年寒□结晶成的戒指，任多大烈焰终不能使之熔化。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 1000, "silver" }) );
        set("extra_stats",(["dex":-1]));
        set("extra_skills",(["meditate":10]));
}



