
#include "../goomay.h"

inherit Mob_special;

void create()
{
	
	::create();
	set_level(4);
	set_name( "mama", "妈妈桑" );
	set_short( "妈妈桑" );
	set_long(
	"一个全身乾瘪却穿得很*暴露*的老婆婆，她正在照看著澡堂的生意。\n"
		 );
	set("alignment",100);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "unit", "个" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 50 ]) );
	set_natural_weapon(4,4,9);
	set_natural_armor(26,0);
        set("special_attack",(["damage_type" : "energy","main_damage" : 6,
                                "random_dam" : 3 , "hit_rate" : 15]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","妈妈桑举起小板凳朝你头上一阵乱砸 ....痛死了...\n\n");
set("c_room_msg","妈妈桑举起她的小板凳朝");
set("c_room_msg2", "一阵乱打，把他打得晕头转向 ...\n");
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                "妈妈桑大叫道：「臭小子 !! 连你祖妈我都要欺负 !! 」。\n",
	}) );
}
