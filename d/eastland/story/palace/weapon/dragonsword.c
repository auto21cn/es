#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Sky longsword","怒龙剑");
        add ("id", ({"longsword","sword" }) );
        set_short("怒龙剑");
        set_long(@LONG
一把剑柄雕刻著双龙头用太白金精打造的武器。剑身的白色光辉达十丈长，发出阵
阵寒气。   
LONG
        );
        set("type", "longblade");
        set("unit","把");
        set("weapon_class",35);
        set("min_damage", 20 );
        set("max_damage", 40);
        set("weight", 100);
        set("value", ({ 1000, "silver" }) );
        set_c_verbs( ({ 
           "的%s发出十丈白色光辉斜劈%s",
           "飞跃而起，手持%s一道人影往%s电射而去",
           "快速地挥动%s，对著%s连砍三刀",
           "准备使出「毁天灭地」的一式，手中%s对著%s的弱点狠狠一击"           
        }) );
}
