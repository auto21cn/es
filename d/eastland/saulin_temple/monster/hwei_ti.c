#include "saulin_monk.c"

void create()
{
	::create();
	set_level(7);
	set_name( "hwei ti", "晦堤" );
	add ("id", ({ "hwei", "ti","monk" }) );
	set_short( "晦堤" );
	set_long(@C_LONG
晦堤从小被父母遗弃在少林寺旁的草丛中，所以他的身世年纪不明... 
他是一个黑暗精灵，所以长的黑黑瘦瘦的，除了专心练功\之外，没有人 
知道他心底在想些什麽... 
C_LONG
	);
	set( "alignment",0);
	set( "gender", "male" );
	set( "race", "drow" );
	set( "unit", "位" );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 8);
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 7);
	set_skill("unarmed",100);
	set_skill("dodge",40);
	set("aim_difficulty", ([ "critical":5, "vascular":4, ]) );
	set("max_fp", 45);
	set("force_effect", 2);
	set("force_points", 45);
	set("attack_skill",FIST"ro_han");
	set("gonfus/ro_han",1);
	set("defense_type","dodge");    
	set("wealth/gold", 11);
	set_natural_weapon( 10, 8, 12 );
	set_natural_armor( 27, 10);
        set("weight", 340);
	equip_armor( SAULIN_OBJ"cloth7" ); 
} 
