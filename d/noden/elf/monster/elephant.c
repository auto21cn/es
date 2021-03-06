#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name( "elephant", "大象" );
        set_short( "大象" );
        set("unit","头");
        set_long(
        "你看见一只巨大的动物，有著长长的鼻子、巨大的耳朵、与两根白色的长牙，\n"
        "此时它正在草原上悠闲的漫步著\n"  
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 3);
        set("max_hp",100);
        set("hit_points",100);
        set ("natural_weapon_class1", 3);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 10);
        set ("natural_armor_class", 25);
        set_c_verbs(({"%s用它的长牙向%s攻击","%s用它的长鼻甩向%s"}));
        set_c_limbs(({"鼻子","身体","耳朵","脚部","头部"}));      
}
