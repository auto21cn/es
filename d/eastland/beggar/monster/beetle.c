#include "../dony.h"      
        
inherit DMONSTER"limit";

void create ()
{               
       ::create();
       set("lvlimit",10);
       set_level(5);
       set_name( "beetle", "甲虫" );
       add( "id",({"beelte",""}) );
       set_short( "甲虫" );
       set("unit","只");
       set_long(
       "这是一只小小的昆虫,它正栖息在树上。\n"
                        );
       set_perm_stat("dex", 4);
       set_perm_stat("str", 4);
       set_natural_weapon(7,4,8);
       set_natural_armor(25,1); 
       set_c_verbs(({"%s用它的巨角往%s一顶"}));
       set_c_limbs(({"腹部","头部","角"}));
}
