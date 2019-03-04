#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(18);
       set_name( "unicorn","独角兽");
        set_short( "独角兽" );
       set("unit","只");
        set_long(
       "这是一只神兽，它有著骏马似的身躯，及一只奇特的角，请\n"
       "不要伤害它，因为有传说若有人伤害它 ，上天将会降祸於世人\n" );
       set_perm_stat("dex", 30);
       set("natural_weapon_class1",35);
       set("natural_armor_class", 80);
       set_perm_stat("str",20);
       set_perm_stat("kar",25);
       set_perm_stat("int",20);
       set_perm_stat("pie",20);
       set_skill("dodge",100);
       set("natural_defense_bonus",24);
       set("alignment",2000);
       set("max_hp",500);
       set("hit_points",500);
       set("natural_min_damage1",19);
       set("natural_max_damage1",35);
       set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的角向%s顶去"}));
       set_c_limbs(({"身体","尾巴","脚部","头部"}));
}
