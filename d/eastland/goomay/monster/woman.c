#include "../goomay.h"

inherit Mob_special;

void create()
{
	object ob;
	::create();
	set_level( 3 );
	set_name( "woman", "家庭主妇" );
	set_short( "家庭主妇" );
        set_long(
@C_LONG
她是一个典型的三姑六婆，买菜聊天是她最大的娱乐，现在她正
高兴的一面挑东拣西一面到处喷口水，显得很兴奋。
C_LONG
);
	set( "gender", "female" );
	set( "race", "human" );

	set("hit_points", 100);
	set( "wealth/silver", 20 );
	set_natural_weapon( 4, 3, 7 );
	set_natural_armor( 16, 6 );
        set_c_verbs(({"%s用指甲抓向%s","%s用菜篮砸向%s","%s用脚踹向%s"}));
        ob = new( Obj"basket" );
        ob->move( this_object() );
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
				"random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "那妇人用她的菜篮往你的头上一阵乱砸..\n\n");
set("c_room_msg","那妇人像疯了似的用菜篮乱砸");
set("c_room_msg2", "，把他打得哀哀叫 ...\n");
        set( "chat_chance", 10 );
        set( "chat_output", ({
                "家庭主妇无奈地说：「猎人阿三病了，这几天都没有飞禽走兽可以进补 」。\n",
	})
	);

}

