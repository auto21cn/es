#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(12);
        set_name( "market guard", "市场警卫" );
        add ("id", ({ "guard"}) );
        set_short( "market guard","市场警卫");
        set("unit","位");
        set_long(@AAA
一个负责维持市场治安的警卫
AAA
        );
        set_skill("blunt",60);
        set_skill("parry",30);
        set("hit_points",200);
        set("max_hp",200);
        set ("natural_weapon_class1", 17);
        set ("natural_min_damage",13);
        set ("natural_max_damage",18);
        set ("natural_armor_class", 40);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",150);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(MOBJ"club.c");
}