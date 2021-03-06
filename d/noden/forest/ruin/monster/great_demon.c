#include "../ruin.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(16);
	set_name( "great demon", "大恶魔" );
	add ("id", ({ "daemon", "demon", }) );
	set_short( "大恶魔" );
	set_long( @C_LONG
黑魔从冥黑的世界呼唤出来的恶魔，在魔界的地位颇高，但亦会死心塌地的
为主人卖命，听从主人的命令，至死方休。
C_LONG
	);
	set( "alignment", -1500 );
    set( "unit", "只" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "con", 22 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 25 );
	set ("max_hp", 720);
	set ("hit_points", 720);
	set ("persuing", 1);
	set ("aggressive", 1);
	set ("killer", 1);
	set_natural_weapon( 45, 20, 35 );
	set_natural_armor( 85, 35 );
    set ("weight", 400);
    set ("exp_reward",10000 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":50, "weakest":40, "ganglion":20, ]) );
    set ("special_defense", 
         ([ "fire":25, "cold":25, "enerage":25, "electric":25, ]) );
    set_experience(20000);
    set_skill("dodge",70);
    set_c_verbs( ({ "%s用爪子抓%s", "%s用角刺%s", "%s踢%s",
                    "%s咬%s", "%s用镰刀横劈%s", }) );
    set_c_limbs( ({ "头", "身体", "脚", "角", "翅膀", }) );
    wield_weapon( OBJ"scythe" );
}
