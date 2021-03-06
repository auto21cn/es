
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
	object helmet,boots,lance,amulet,leggings,plate,cloak;

	::create();
	set_level(14);
	set_name( "daemonic fighter", "恶魔战士" );
	add ("id", ({ "fighter", "daemon" }) );
   set_short( "恶魔战士" );
	set("unit","位");
   set_long(
	   " 他是当恶魔入侵精灵村时被引入迷宫的残存恶魔族人，是一位可怕的战士。\n"
	);
	set("alignment",-1000);
	set("wealth/gold",20);
	set_perm_stat("str", 17);
	set_perm_stat("dex", 18);
	set_perm_stat("kar",10);
	set_natural_weapon( 10, 6, 8 );
	set ("natural_armor_class", 20);
	set ("gender", "male");
	set ("race", "daemon");
	set( "tactic_func", "my_tactic" );
	set_c_verbs(({"用%s向%砍去","用%s使出必杀一击向%s攻击","用%s向%s刺去"}));
	set_c_limbs(({"身体","头部","脚部","手臂"}));
       
	set_skill("parry", 75);
	set_skill("thrusting", 75);

	set("natural_defense_bonus",10);
	wield_weapon(LWEAPON"daemon_lance");      
	equip_armor(LARMOR"daemon_boots");
	equip_armor(LARMOR"daemon_amulet");
	equip_armor(LARMOR"daemon_leggings");
	equip_armor(LARMOR"daemon_plate");
	equip_armor(LARMOR"daemon_cloak");
	equip_armor(LARMOR"daemon_helmet");
}


int my_tactic()
{
	object *victim;

	if( random(20)>2 || !(victim= query_attackers()) ) return 0;
   tell_room( environment(),
		"\n恶魔战士发出可怕的吼叫声，并且用一种奇异的语言开始念咒 ....\n"
           "\n你觉得眼前一黑, 某种神秘的力量击中你的心脏, 使你痛苦不堪!\n\n",
		this_object() );
	victim->receive_special_damage( "evil", 40 );
	return 1;
}
