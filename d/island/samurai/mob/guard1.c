#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(14);
        set_name( "red samurai", "红衣武士" );
        add ("id", ({ "samurai","red"}) );
        set_short( "red samurai","红衣武士");
        set("unit","位");
        set_long(@AAA
红衣武士是武士团中等级较高的武士，同时也表示其剑术也较高,为
武士团战力的核心
AAA
        );
        set_skill("longblade",70);
        set_skill("parry",60);
        set("hit_points",250);
        set("max_hp",250);
        set ("natural_weapon_class1", 27);
        set ("natural_min_damage",13);
        set ("natural_max_damage",18);
        set ("natural_armor_class", 40);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",300);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(MOBJ"wind_blade_sword.c");
        equip_armor(MOBJ"samurai_chainmail.c");
}