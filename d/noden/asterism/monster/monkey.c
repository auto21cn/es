#include "../asterism.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(3);
       set_name( "monkey", "猴子" );
       set_short( "monkey","猴子");
       set("unit","只");
       set_long("",
       "这只猴子吊在树上晃啊晃，还不时转头窥看你的行动。\n"       
       "你看，它又瞪著鼓露露的大眼望著你了。\n"
                        );
       set_perm_stat("dex", 2);
       set ("natural_weapon_class1", 4);
       set ("natural_min_damage1",5);
       set ("natural_max_damage1", 8);
       set ("natural_armor_class", 13);
       set_c_verbs(({"%s用它的手向%s抓去","%s用它的牙齿向%s咬去"}));
       set_c_limbs(({"身体","脚部","头部"}));
}

