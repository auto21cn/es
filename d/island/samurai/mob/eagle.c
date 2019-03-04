#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Eagle Nanaruha ", "老鹰 那那鲁哈" );
        add ("id", ({ "eagle","nanaruha"}) );
        set_short( "Eagle Nanaruha","老鹰 那那鲁哈");
        set("unit","位");
        set_long(@AAA
那那鲁哈是一只凶猛的大鹰，拥有强健的翅膀与尖锐的爪牙，是娜考露露的好
友，经常旁在娜考露露的身旁！！
AAA
        );
        set("hit_points",350);
        set("max_hp",350);
        set ("natural_weapon_class1", 50);
        set ("natural_min_damage1",15);
        set ("natural_max_damage1",45);
        set ("natural_armor_class", 65);
        set("natural_defense_bonus",18);
        set_c_limbs(({"身体","头部","爪子","翅膀"}));
        set_c_verbs( ({"%s向下俯冲，撞向%s","%s用尖锐的爪子抓向%s","%s用翅膀拍向%s"}) );
       
}