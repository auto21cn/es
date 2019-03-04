#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(6);
       set_name( set_color("Crab","HIY"),set_color("小螃蟹","HIY") );
       add("id",({"crab"}) );
       set_short( set_color("小螃蟹","HIY") );
       set("unit","只");
       set_long(set_color("
    
      ∪        ∪
     □ ⊙  ⊙ □
    《\\┴—┴/《    　一只全身黄色的小螃蟹，不知道是属於什麽种类。
    《｜    □《　　   它现在正在补食。
     □———□

       
       \n","HIY"));
       set_natural_armor(30,0);
       set_natural_weapon(9,5,9);
       set_c_verbs(({"%s用它的螯向%s攻击"}));
       set_c_limbs(({"身体","头部","壳"}));
}

