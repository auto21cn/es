#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(11);
        set_name( "turtle", "壮年龟" );
        set_short("壮年龟");
        set("unit","只");
        set_long(@LONG
本岛特产，大型海龟，不过据说山上也有，它现在正值壮年。
LONG
        );
        set_perm_stat("str", 14);
        set_perm_stat("dex", 14);
        set ("max_hp",200);
        set ("hit_points",200);
        set ("wimpy",100);
        set ("pursuing",1);
        set ("likefish",1);
        set ("natural_weapon_class1",11);
        set ("natural_min_damage1", 9);
        set ("natural_max_damage1", 17);
        set_natural_armor( 33,12);
        set_c_verbs(({"%s用整个身体向%s撞来","%s用它的硬壳向%s攻击"}));
        set_c_limbs(({"尾巴","壳","脚部","头部"}));      
}
