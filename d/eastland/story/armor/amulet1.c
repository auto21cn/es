#include "../story.h"
inherit ARMOR;
inherit SARM"OR";

void create()
{
        set_name("buddha amulet","□符");
        add( "id", ({ "amulet" }) );
        set_short( "□符");
        set_long(@C_LONG
一个绣著□字符号的护符。除此之外，护符上满是些佛字梵号，不时闪烁著光芒，
其光芒令你感到一阵阵的温暖，相信是个很好的防具才对。
C_LONG
        );
        set("unit","个");
        set( "type", "misc" );
        set("material","cloth");
        set("the_one",1);
        set( "defense_bonus", 1 );
        set( "weight", 1 );
        set( "value", ({ 600, "gold" }) );
}



