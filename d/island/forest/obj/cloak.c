#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Hawk Cloak","光鹰斗蓬");
    add("id", ({ "cloak","soup" }) );
    set_short("光鹰斗蓬");
    set_long(@C_LONG
这是树雷王家成员战斗时专用的披风。当王族穿上此披风时，防御力将会倍增。加上
由於质地轻巧，无形中增加了机动力，所以成为王族的最爱。可不要小看这件披风哦
，它可是收集罕见的『光鹰羽』所织成的哦！
C_LONG
           );
    set("unit","件");
    set("type","cloak");
    set("material","leather");
    set("armor_class",8 );
    set("defense_bonus",4 );
    set("special_defense", (["fire":10,"cold":10,"divide":-20,"poison":-30]) );
    set("weight",100);
    set("value",({1200,"silver"}) );
}
