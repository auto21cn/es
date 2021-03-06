#include "../legend.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Chu pao kun", "诸保昆" );
        add ("id", ({ "chu", "pao", "kun" }) );
        set_short( "诸保昆");
        set_long(@CLONG
诸保昆是四川青城派弟子，在武术造诣上为青城第一把交椅，仅次於目前得青城掌
门木华生。七年前，诸保昆离开青城，投入军营中，以非凡的武功过人的胆识，深
得上司的青睐。近来由於长年在外征战，难得有归乡探望亲人的机会。这一次借著
调查流窜的敌军下落，顺道经由此地返家。
CLONG
        );
        set_perm_stat("int",25 );
        set_perm_stat("str", 30 );
        set_perm_stat("dex", 30 );
        set_perm_stat("kar", 30 );
        set_skill( "chain",100);
        set_skill( "polearm",100);
        set_skill( "parry", 100 );
        set_skill( "dodge", 100 );
        set_skill( "two-weapon", 100);
        set_temp("bs",30);
        set( "alignment", 2000);
        set( "race", "human" );
        set( "gender", "male" );
        set( "hit_points", 1800 );
        set( "max_hp", 1800 );
        set( "spell_points", 180000 );
        set( "max_sp", 180000 );
        set( "max_fp", 1000 );
        set("time_to_heal",7);
        set_natural_weapon( 10, 25, 20 );
        set_natural_weapon2( 19, 18, 19 );
        set_natural_armor( 71, 37 );
        set("special_defense",(["all":75,"cold":20, "none":70]) );
        set("aim_difficulty",([ "critical":100]) );
        set("stun_difficulty",100);
        set_temp("be_joke",100);
        set("war_score",100000);
        wield_weapon( LWEAPON"t_star");
        wield_weapon2( LWEAPON"wind_awl" );
        equip_armor( LARMOR"iron_plate" );
        equip_armor( LARMOR"iron_armband");
}

