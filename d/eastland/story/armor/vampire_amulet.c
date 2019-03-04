#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("night-Ghost amulet","九魔阴阳符");
        add( "id", ({ "amulet"}) );
        set_short( "九魔阴阳符");
        set_long(@C_LONG
九魔阴阳符相传经由七七四十九天，由九个厉鬼生啖三十六个男女童再引入地磁真
火练化那九个厉鬼而制成的，由於此法大干天和，故制作之後那持有人便遭雷亟，
之後，这符就不知道下落，据说，最後辗转流入「妖□　谷辰」之手。
C_LONG
        );
        set("unit","张");
        set( "type", "misc" );
        set("material","cloth");
        set( "defense_bonus", 6 );
        set( "weight",5 );
        set("special_dfense",
                     (["evil":20]) );
        set( "value", ({ 2500, "silver" }) );
}



