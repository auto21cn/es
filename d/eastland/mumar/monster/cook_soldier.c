#include <../mumar.h>
inherit "/d/eastland/mumar/monster/mob_special";
 
void create()
{
        object ob;
        ::create();
        set_level( 3 );
        set_name( "cooking soldier", "伙房兵" );
        add ("id", ({ "soldier" }) );
        set_short( "伙房兵" );
        set_long( @C_LONG
他是一个典型的伙夫，看起来好像很喜欢这份工作，显得很高兴。
C_LONG
);
        set( "gender", "male" );
        set( "race", "human" );
 
        set("hit_points", 100);
        set( "wealth/silver", 20 );
        set_natural_armor( 16, 6 );
        set_c_verbs(({"%s用头撞向%s","%s用勺子槌向%s","%s用脚踹向%s"}));
        wield_weapon(OBJS"scoop");
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
                                "random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
        set("c_enemy_msg",
            "伙房兵用勺子挖起一堆菜渣，往你的脸上乱扔..\n\n");
        set("c_room_msg","那伙房兵脸上浮起一阵奸笑，同时挖起一堆剩菜渣，扔向");
        set("c_room_msg2", "，哇...你觉得乱恶心一把的.....\n");
 
        set( "chat_chance", 5 );
        set( "chat_output", ({
        "伙房兵说道 : 头头这几天的心情(mood)好像怪怪的,不知怎麽了...\n",
        "伙房兵用勺子搅动著锅里的汤...\n"
        }) );
}
