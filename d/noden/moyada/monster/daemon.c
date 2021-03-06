#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(15);
	set_name( "daemon shadow", "恶魔" );
	add ("id", ({ "daemon", "demon", }) );
	set_short( "恶魔" );
	set_long( @C_LONG
生活於冥黑的世界的恶魔，在魔界的地位颇高，但亦会死心塌地的
为主人卖命，听从主人的命令，至死方休。
C_LONG
	);
	set ("alignment", -2000 );
    set ("unit", "只" );
    set ("race", "daemon");
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 25 );
	set ("c_death_msg", "%s尖叫一声:%#$@&*@*!%&&(你听不懂，可能是外语).... 然後就死了!\n" );
	set ("max_hp", 1000);
	set ("hit_points", 1000);
	set ("persuing", 1);
	set ("time_to_heal", 3);
	set ("aggressive", 1);
	set ("aim_difficulty", ([ "critical" : 50, ]) );
	set ("unbleeding", 1);
	set_natural_weapon( 40, 15, 20 );
	set_natural_armor( 70, 30 );
    set ("weight", 400);
    set ("exp_reward", 9000 );
    set ("special_defense", 
         ([ "all":35 ]) );
    set_skill("shortblade", 80);
    set_experience(20000);
    set_skill("dodge",70);
    set_c_verbs( ({ "%s用爪子抓%s", "%s用角刺%s", "%s踢%s",
                    "%s咬%s", "%s用死神镰刀横劈%s", }) );
    set_c_limbs( ({ "头", "身体", "脚", "角", "翅膀", }) );
    wield_weapon(MOYADA"obj/d_death_scythe");
}

void die()
{
	object killer;

	killer = query("last_attacker");
	if( killer ) killer->set_temp("wanfu/done",1);
	::die();
}
