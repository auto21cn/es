#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(2);
       set_name( "butterfly", "凤仙蝶" );
        set_short( "凤仙蝶" );
       set("unit","只");
        set_long(
       "这是一只美丽的凤仙蝶，此刻正在四处上轻快的飞舞著，有如风之舞者。\n"
                        );
       set("moving",1);
       set("speed",25);                  
       set_perm_stat("dex", 4);
       set ("natural_weapon_class1", 6);
       set ("natural_min_damage1",2);
       set ("natural_max_damage1", 4);
       set ("natural_armor_class", 5);
		setenv( "C_MIN", "一只$N翩翩的飞了过来。");
        setenv( "C_MOUT", "$N翩翩地往$D边飞去。");
       set_c_verbs(({"%s用它的翅膀向%s扑击"}));
       set_c_limbs(({"身体","头部"}));
}
