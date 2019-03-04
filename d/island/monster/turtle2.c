#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(3);
        set_name( "turtle", "小龟" );
        set_short("小龟");
        set("unit","只");
        set_long(@LONG
本岛特产，大型海龟，不过据说山上也有，它还年轻不要欺负它！
LONG
        );
        set_perm_stat("str", 4);
        set_perm_stat("dex", 4);
        set("max_hp",65);
        set("hit_points",65);
        set("wimpy",30);
        set("pursuing",1);
        set("likefish",1);
        set ("natural_weapon_class1", 4);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 15);
        set_c_verbs(({"%s用整个身体向%s撞来","%s用它的硬壳向%s攻击"}));
        set_c_limbs(({"尾巴","壳","脚部","头部"}));      
}
