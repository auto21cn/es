#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "we-tow staff", "韦陀杵");
        add ("id",({ "staff"}) );
        set_short("韦陀杵");
        set("unit", "把");
        set_long(@C_LONG
这是一把由千年紫檀木做成的禅杖，上面的雕工十分的精细，你一看就知道
这一定是某个师傅穷毕生的精力所完成的。同时这也是少林寺方丈的信物。
C_LONG
        );
        set("weapon_class", 30);
        set("type", "bo");
        set("min_damage", 20);
        set("max_damage", 40);
        set("weight", 220 );
        set("no_sale",1);
        set("value", ({ 2500, "silver" }) );
}
