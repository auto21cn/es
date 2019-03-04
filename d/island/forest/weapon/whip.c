#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Thunder Whip","雷神鞭");
    add("id",({"whip"}) );
    set_short("雷神鞭");
    set_long(@C_LONG
据说这是上古雷神鲁特所持的神鞭。
C_LONG
            );
    set("unit","条");
    set("type","whip");
    set("weapon_class",13);
    set("min_damage",5);
    set("max_damage",10);
    set("second",1);
    set("value",({ 350,"silver"}) );
    set_c_verbs( ({"的%s如晴天霹雳般向%s直击而去",
       "将%s甩成连绵不绝的圆圈圈卷向%s","的%s在地上游走不定，突然扫向%s"}) );
}    