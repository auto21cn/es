#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(14);
        set_name( "Ninja", "忍者" );
        add ("id", ({"ninja"}) );
        set_short( "Ninja","忍者");
        set("unit","位");
        set_long(@AAA
这是武士团的秘密部队，忍者军团的一员，他们和武士不同之处在於他们是负责
敌後破坏工作，而非正面刺杀，但你可别因此小看他们的战力喔．
AAA
        );
        set_skill("longblade",70);
        set_skill("parry",60);
        set_skill("dodge",60);
        set("hit_points",300);
        set("max_hp",300);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",25);
        set ("natural_armor_class", 64);
        set("natural_defense_bonus",10);
        set ("gender", "male");
        set("wealth/silver",320);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(MOBJ"ninja_sword.c");
        equip_armor(MOBJ"ninja_cloth.c");
}
