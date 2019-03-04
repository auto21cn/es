#include <../goomay.h>
inherit Mob_special;

void create ()
{
        ::create();
        set_level(12);
        set_name( "Lui Chu", "绿珠" );
        add ("id",({ "chu","lui"}));
        set_short( "绿珠");
        set("unit","位");
        set_long(
@C_LONG
    在你面前的是一个十分罕见的美丽女子，气质高雅的她正微笑地看著你，
她是绿珠，一个出身贫寒却聪慧过人的姑娘，她现在正站在花丛之中整理她的
宝贝们，你呆呆地看著她，不知道是人因为花显得更美丽还是花因为人开的更
娇艳。
C_LONG
);
        set("alignment",550);
        set_perm_stat("str",17);
        set_perm_stat("dex",17);
        set_perm_stat("int",17);
        set_natural_armor( 72, 21 );
        set_natural_weapon( 6, 4, 9 ); 
        set_skill("dodge",85);
        set_skill("whip",80);
        set ("gender", "female");
        set ("race", "human");
        set( "special_defense", ([ "all": 30 ]) );

        wield_weapon( Obj"ribbon" );
		equip_armor(Obj"web");
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "root": "@@ask_root",
        ]) );
        set("special_attack",(["damage_type" : "mental","main_damage" : 20,
                                "random_dam" : 10 , "hit_rate" : 15 ]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "绿珠的丝带柔柔地套上你的脖子，把你箍的连气都透不过来..\n\n");
set("c_room_msg","绿珠轻柔地挥动著丝带，把");
set("c_room_msg2", "箍的气也透不过来 ...\n");

}
int ask_root()
{
	object ob1;
	if (this_player()->query_temp("amaze_root"))
	{
        tell_object(this_player(),
			"绿珠说：「我不是已经把药给你了吗？」\n");
	return 1;
	}
        tell_object(this_player(),
"绿珠叹了一口气道：「老爷也真是的，怎麽可以拿人命来做生意呢？我会\n"
"劝劝他的，谢谢你的提醒。我想药物很快就会到了 !! 」她拿出一段树根\n"
"道：「这是奇异花树的根，请您先拿去急用吧 !!」\n" );

        ob1 = new( Obj"amaze_root" );
        ob1->move(this_object());
		this_player()->set_temp("amaze_root",1);
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
        return 1;
}
