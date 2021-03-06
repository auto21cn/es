#include "mercury.h"
inherit MONSTER;


void create()
{
	::create();
	set_level(19);
	set_name( "Swordman Fan", "云游剑客 方歌吟" );
	add( "id", ({ "swordman","fan" }) );
	set_short( "Swordman Fan", "云游剑客 方歌吟" );
	set_long(
@LONG
方歌吟是一个已经没落的剑派的掌门，为求剑派的再复兴，他四处寻人比武以提
升剑技，他的必杀剑法天羽二十四剑威力其大，你如果想向他挑战的话最好三思
而行！！
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "likefish" , 1 );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "dex", 30 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "unarmed",100);
	set_skill( "tactic",100);
	set("tactic","berserk");
	set( "max_hp", 800 );
	set( "hit_points", 800 );
	set_natural_armor( 60, 25 );
	set_natural_weapon( 20, 10, 30 );
	set( "special_defense", ([ "all": 50,"none":60,"fire":50,"cold":50]) );
	set( "aim_difficulty",([ "weakest":30,"vascular":20 ]) );
	set( "alignment", 2800 );
        wield_weapon(MOBJ"sword1.c");
        equip_armor(MOBJ"tanyu_amulet.c");
        equip_armor(MOBJ"tanyu_cloth.c");
        equip_armor(MOBJ"tanyu_cloak.c");
        equip_armor(MOBJ"tanyu_armband.c");
        equip_armor(MOBJ"tanyu_gloves.c");
        equip_armor(MOBJ"tanyu_ring.c");
        equip_armor(MOBJ"tanyu_boots.c");
}
