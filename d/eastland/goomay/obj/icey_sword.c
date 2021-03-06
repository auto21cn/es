#include <../goomay.h>

inherit Weapon_special;

void create()
{
	set_name( "Sword of snow", "吹雪剑" );
	add( "id", ({ "sword" }) );
	set_short( "吹雪剑" );
	set_long(
		"这是一把奇特的短剑，剑刃上浮现出一片片六角形如雪花一般的\n"
		"印痕，虽然你只是看它一眼，但也似乎能感受到那股丝丝寒意。\n"
	);
	set( "unit", "把" );
	set( "weight", 150 );
	setup_weapon( "shortblade", 37, 20, 32 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);

        set("special_attack",(["damage_type" : "cold","main_damage" : 10,
                                "random_damage" : 10 , "hit_rate" : 15]));
//        set("hit_func","special_attack");

set("c_msg","\n你的吹雪剑喷出一片奇冷的寒气，冰冻敌人的身体。\n\n");
set("c_enemy_msg","的吹雪剑喷出一片奇冷的寒气，冰冻你的身体。\n\n");
set("c_fail_msg","\n你的吹雪剑喷出一片奇冷的寒气，却冰到你自己 ! \n\n");
set("c_fail_room_msg","的吹雪剑喷出一片奇冷的寒气，却冰到他自己 ! \n\n");
}

int fail_to_use()
{
	object ob;
	if ( !(ob = present("flame shield", environment(this_object()) )) ||
			    !(ob->query("equipped")) )
	       return 1;
	else
	       return 0;
}
