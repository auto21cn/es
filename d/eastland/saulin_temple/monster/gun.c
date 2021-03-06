#include "saulin_monk.c"

void create()
{
	::create();
	set_level(17);
	set_name( "master kon gun", "戒律院首座 空刚" );
	add ("id", ({ "master", "kon", "gun","kon gun" }) );
	set_short( "戒律院首座 空刚" );
	set_long(
@C_LONG
戒律院负责少林众僧之戒规惩处，所有僧人回寺後的第一件事便是赴戒律院
报告此行云游的功\过。空刚人如其名，性格刚烈，无惧任何邪恶豪强。他曾
一人单挑武夷十三怪，奋战三天，浴血而回... 所以他被方丈选为戒律堂首
座。
C_LONG
	);
	set( "alignment",1600);
	set( "gender", "male" );
	set( "race", "human" );
	set( "unit", "位" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 21 );
	set_skill("unarmed",100);
	set_skill("block",90);
	set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_points", 500);
	set("wealth/gold", 50);
	set_natural_weapon( 25, 24, 37 );
	set_natural_armor( 45, 40 );
	set("weight", 500);
	set("chat_chance", 10);
	set("chat_output", ({
		"空刚说: 少林寺僧当守五戒: 戒妄语, 戒淫邪, 戒饮酒 .....\n",
	}) ); 
	set("att_chat_output", ({
	    "空刚合十道：「施主於我少林寺大开杀戒，就让我空刚来渡化你吧 !」\n",
	}) );
	set("attack_skill",CLASS"dragon_claw");
	set("monk_gonfu/dragon-claw",10);
//	wield_weapon( SAULIN_OBJ"go.c" );
	equip_armor( SAULIN_OBJ"cloth2a.c" );
//	equip_armor( SAULIN_OBJ"shield2.c" );
	equip_armor( SAULIN_OBJ"armband1.c" );
}
