#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(11);
   set_name( "sexual Devil", "万恶淫魔" );
   add( "id", ({ "devil" }) );
   set_short( "万恶淫魔" );
	set_long(
           "他就是东方大陆中恶名昭彰, 令人深恶痛绝的万恶淫魔。\n"
           "不用多说, 你只要『拼命』把他宰了!\n"
	);
   set_perm_stat( "str", 12 );
   set_perm_stat( "int", 15 );
   set_perm_stat( "dex", 15 );
   set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "natural_armor_class", 40 );
   set( "natural_defense_bonus", 15 );
   set( "natural_weapon_class1", 20 );
   set( "natural_min_damage1", 10 );
   set( "natural_max_damage1", 15 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
        "万恶淫魔脸上露出邪恶的笑容。\n",
        "万恶淫魔奸笑道: 嘿嘿嘿 .... 别逃 .... 让我吸点精气吧!\n",
	}) );
}

int my_tactic()
{
	object *victim;
	int i;

   if( random(20)<16 || !(victim = query_attackers()) ) return 0;
   tell_room( environment(this_object()),
      "\n万恶淫魔突然施展秘术『吸魂大法』夺去你部份的元神!\n\n",
		this_object() );
   for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "evil", 30 );
	return 1;
}

void die()
{
   object killer;

	killer = query("last_attacker");
   killer->set_temp( "kill_ian_devil", 1 );
   tell_room( environment(this_object()),
     "万恶淫魔喊道: 噢 .... 不 .... 我还要享受美女!\n" );
   tell_object( killer,
    "\n原来『万恶淫魔』竟躲在烟雨村, 而且还杀了自己的女儿! 真是\n"
      "人间一大悲剧! 你心想此事真残酷, 正踌躇是否应告知(inform)\n"
      "郭长老。\n\n" );
   ::die(1);
}
