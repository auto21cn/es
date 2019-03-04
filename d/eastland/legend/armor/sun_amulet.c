#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name("sun amulet", "日符");
     add( "id", ({ "amulet" }) );
     set_short( "日符");
     set_long(@C_LONG
一个有著九颗太阳的护符。相传这护符上的九日是被后羿射下的乌鸟的魂魄附著而
成的，於是你握在手中还会感觉到阵阵的温暖传来。
C_LONG
     );
     set("unit","个");
     set("material","cloth");
     set( "type", "misc" );
     set( "defense_bonus", 9 );
     set( "weight", 5 );
     set( "value", ({ 150, "gold" }) );
}