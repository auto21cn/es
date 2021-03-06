#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "gray samurai", "灰衣武士" );
        add ("id", ({ "samurai","gray"}) );
        set_short( "gray samurai","灰衣武士");
        set("unit","位");
        set_long(@AAA
灰衣武士是武士团中等级最低的武士，专门负责守卫及巡逻的工作
AAA
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 12);
        set_skill("longblade",50);
        set_skill("parry",45);
        set ("natural_weapon_class1", 12);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 30);
        set("natural_defense_bonus",6);
        set ("gender", "male");
        set("wealth/silver",60);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(MOBJ"east_feather_blade.c");
        equip_armor(MOBJ"samurai_chainmail.c");
}
