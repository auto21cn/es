#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(5);
       set_name( "crab", "小螃蟹" );
       add("id",({"crab"}) );
       set_short( "小螃蟹" );
       set("unit","只");
       set_long("
    
      ∪        ∪
     □ ⊙  ⊙ □
    《\\┴—┴/《    　一只全身纯白的小螃蟹，它正辛勤挖洞，瞧它忙得不亦乎，
    《｜    □《　　   似乎忽略了你的存在。
     □———□

       
       \n");
       set_natural_armor(25,0);
       set_natural_weapon(7,4,8);
       set_c_verbs(({"%s用它的螯向%s攻击"}));
       set_c_limbs(({"身体","头部","壳"}));
}

