#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(4);
       set_name( set_color("Crab","HIG"), set_color("小螃蟹","HIG") );
       add("id",({"crab"}) );
       set_short( set_color("小螃蟹","HIG") );
       set("unit","只");
       set_long(set_color("
    
      ∪        ∪
     □ ⊙  ⊙ □
    《\\┴—┴/《    一只全身青色的小螃蟹，它正瞪著你瞧，小小的眼睛
    《｜    □《　　 ，模样可爱极了。  
     □———□

       
       \n","HIG"));
       set_natural_armor(20,0);
       set_natural_weapon(5,3,6);
       set_c_verbs(({"%s用它的螯向%s攻击"}));
       set_c_limbs(({"身体","头部","壳"}));
}

