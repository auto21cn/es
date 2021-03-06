#include "saulin_monk.c"

void create()
{
	::create();
	set_level(9);
	set_name( "shi hur", "虚合大师" );
	add ("id", ({ "shi", "hur","monk" }) );
	set_short("虚合大师" );
	set_long( @LONG
虚合是个精通五种少林绝技的老僧，一生隐居少林，几乎不曾出去过。
虚合大师唯一的兴趣就是练武，所以能当上他的徒弟是你的福气啦!!!
般若(音读 玻惹 )掌是少林武僧最常习练的一种拳法，它博大精深，又
足以克敌致胜，昔日少林第八代方丈元元大师创此掌法，而後经历代改
良迄今，算是少林的招牌拳法。
LONG
	);
    set( "alignment",1500);
    set( "gender", "male" );
    set( "race", "lizardman" );
    set( "unit", "位" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 18);
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("class", "monk");
	set("forgetful", 1);
          set("attack_skill",CLASS"bolo_fist");
          set("defense_skill",CLASS"chu_han");
          set("defense_type","berserk");    
          set("monk_gonfu/bolo-fist",10);
          set("monk_gonfu/chu-han",10);
	set("wealth/gold", 10);
	set_natural_weapon( 40, 18,28 );
	set_natural_armor( 55, 35 );
        set("weight", 700);
	set("att_chat_output", ({
	    "虚合说道 『般若掌的威力看见了吧』\n ", 
	}) );
    equip_armor( SAULIN_OBJ"cloth2.c" );
    equip_armor( SAULIN_OBJ"ring1.c" );
}
