#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(8);
        set_name( "turtle", "老龟" );
        set_short("老龟");
        set("unit","只");
        set_long(@LONG
本岛特产，大型海龟，不过据说山上也有
LONG
        );
        set_perm_stat("str", 9);
        set_perm_stat("dex", 9);
        set("max_hp",150);
        set("hit_points",150);
        set("wimpy",70);
        set("likefish",1);
        set ("natural_weapon_class1", 6);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 12);
        set_natural_armor( 25,6);
        set_c_verbs(({"%s用整个身体向%s撞来","%s用它的硬壳向%s攻击"}));
        set_c_limbs(({"尾巴","壳","脚部","头部"}));      
}
