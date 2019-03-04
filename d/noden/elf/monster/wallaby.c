#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(1);
        set_name( "wallaby", "小袋鼠" );
        set_short( "小袋鼠" );
        set("unit","只");
        set_long(
        "你看见一只可爱的动物在草原上蹦蹦跳跳地游玩著\n"  
        );
        set_perm_stat("str", 3);
        set_perm_stat("dex", 3);
        set ("natural_weapon_class1", 3);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 3);
        set ("natural_armor_class", 5);
        set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的拳头向%s攻击"}));
        set_c_limbs(({"身体","耳朵","脚部","头部"}));      
}
