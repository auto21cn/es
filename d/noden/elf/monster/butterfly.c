#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(1);
       set_name( "butterfly", "蝴蝶" );
        set_short( "蝴蝶" );
       set("unit","只");
        set_long(
       "这是一只美丽的昆虫，此刻正在花朵上轻快的飞舞著\n"
                        );
       set_perm_stat("dex", 3);
       set ("natural_weapon_class1", 5);
       set ("natural_min_damage1",1);
       set ("natural_max_damage1", 3);
       set ("natural_armor_class", 5);
       set_c_verbs(({"%s用它的翅膀向%s扑击"}));
       set_c_limbs(({"身体","头部"}));
}
