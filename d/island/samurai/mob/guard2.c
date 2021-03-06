#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "white samurai", "白衣武士" );
        add ("id", ({ "samurai","white"}) );
        set_short( "white samurai","白衣武士");
        set("unit","位");
        set_long(@ANGEL
白衣武士是武士团中等级最高的武士，仅次於队长级的职位，是武士团中的精英份子
ANGEL
        );
        
        set_skill("longblade",70);
        set_skill("parry",60);
        set_skill("tactic",50);
        set("tactic","melee");
        set ("natural_weapon_class1", 33);
        set ("natural_min_damage1",13);
        set ("natural_max_damage1",18);
        set ("natural_armor_class", 45);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",300);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(MOBJ"lakonia_sword.c");
        equip_armor(MOBJ"samurai_vest.c");
        equip_armor(MOBJ"samurai_gloves.c");
}