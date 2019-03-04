#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(3);
       set_name( "marmot", "土拨鼠" );
        set_short( "土拨鼠" );
       set("unit","只");
        set_long(
       "你看见一只可爱的动物，正从地洞里偷偷的望著你，当你走过去想\n"       
      " 抚摸它时，他飞快的躲入洞里，一副怕羞的模样\n"
                        );
       set_perm_stat("dex", 2);
       set ("natural_weapon_class1", 4);
       set ("natural_min_damage1",8);
       set ("natural_max_damage1", 11);
       set ("natural_armor_class", 15);
       set_c_verbs(({"%s用它的前爪向%s抓去","%s用它的牙齿向%s咬去"}));
       set_c_limbs(({"身体","脚部","头部"}));
}

