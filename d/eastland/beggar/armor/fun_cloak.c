#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("moon cloak", "元阴斗蓬");
        add( "id", ({ "cloak" }) );
        set_short( "元阴斗蓬");
        set_long(@C_LONG
这是一件颇大的斗蓬。元阴斗蓬是多年放在千年寒冰之下而制成的,在一万件之中
只可能有一件, 可说是珍贵无比。这件斗蓬上还附有制造者的阴寒内力,用来防冰
系攻击是最好不过的一件东西了。
C_LONG
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus",6 );
        set("special_defense",(["cold":5]) );
        set( "weight", 50 );
        set( "value", ({ 110, "gold" }) );
}



