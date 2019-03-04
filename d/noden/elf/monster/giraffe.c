#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(4);
        set_name( "giraffe", "长颈鹿" );
        set_short( "长颈鹿" );
        set("unit","只");
        set_long(
        "你看见一只有很长脖子的动物在草原上悠闲的走著。\n"  
        );
        set_perm_stat("str", 4);
        set_perm_stat("dex", 8);
        set ("natural_weapon_class1", 5);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 20);
        set_c_verbs(({"%s用它的腿向%s踢去","%s用它的头由上而下向%s攻击"}));
        set_c_limbs(({"身体","脚部","头部"}));      
}
