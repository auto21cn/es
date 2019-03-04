#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("cloak of Wing race", "大首领披风");
        add( "id", ({ "cloak" }) );
        set_short( "大首领披风");
        set_long(@C_LONG
这是一件由千年蚕丝缝制成的斗蓬，手工细致，不但通风，穿起来亦冬暖夏凉，舒
适极了。
C_LONG
        );
        set("unit","件");
        set("type", "cloak" );
        set("material","cloth") ;
        set( "armor_class",7 );
        set("defense_bonus", 6 );
        set("weight", 50 );
        set("extra_skills",(["meditate":10]));
        set("extra_stats",(["dex":-1]));
        set("value", ({ 210, "gold" }) );
}



