#include "../dony.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(4);
       set_name( "grass hopper", "蚱蜢" );
       add( "id",({"grass","hopper"}) );
       set_short( "蚱蜢" );
       set("unit","只");
       set_long(
       "这是一只小小的昆虫,它正跳来跳去的。\n"
                        );
       set_perm_stat("dex", 3);
       set_natural_weapon(5,2,4);
       set_natural_armor(5,1); 
//       set( "moving", 1 );
//       set( "speed", 30 );
//       set ("pursuing", 1) ;
//       setenv( "C_MIN", "一只$N跳了过来。");
//       setenv( "C_MOUT", "$N往$D边跳了过去。");
       set_c_verbs(({"%s用它的腿向%s踢去"}));
       set_c_limbs(({"腹部","头部","腿"}));
}
