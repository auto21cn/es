#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(6);
        set_name( "turtle", "巨龟" );
        set_short("巨龟");
        set("unit","只");
        set_long(@LONG
本岛特产，大型海龟，不过据说山上也有
LONG
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 8);
        set("max_hp",100);
        set("hit_points",100);
        set("wimpy",50);
        set("pursuing",1);
        set ("natural_weapon_class1", 5);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 20);
        set ("likefish",1);
        set_c_verbs(({"%s用整个身体向%s撞来","%s用它的硬壳向%s攻击"}));
        set_c_limbs(({"尾巴","壳","脚部","头部"}));      
}
