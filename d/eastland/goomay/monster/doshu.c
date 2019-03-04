
#include <../goomay.h>

inherit MONSTER;

void create ()
{
        ::create();
        set_name( "daoist", "道士" );
        set_short( "道士");
        set_long(
@C_LONG
    他是一个普普通通的道士，，此刻他的脸上充满了惊恐，因为他发现了
一个翻箱倒柜的小偷。
C_LONG
);
        set_level(9);
        set ("gender", "male");
        set ("race", "human");
		set("killer",1);
        set( "alignment", 400 );
        set_natural_armor( 40, 15 );
		set_natural_weapon( -7,1,4);
        set_perm_stat( "str", 15 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
		set_skill( "shortblade",60);
		set( "max_fp",500);
		set( "force_points",500);
		set( "force_effect",2);
        set( "hit_points", 200 );
        set( "max_hp", 200 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "wealth/silver", 200 );

	wield_weapon( Obj"shortsword01" );
	equip_armor( Obj"doshu_robe" );

        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                "那道士扯起喉咙大喊：「来人啊 !! 有小偷啊 !!」。\n",
                "道士叫道：「我师傅就要来了，臭贼且莫猖狂 !!」。\n"
	}) );
}
void die()
{
	if (!present("The master daoist",environment())) {
                tell_room( environment(this_object()), 
		set_color("\n\n突然，一柄透明的剑向你的咽喉刺来，你大吃一惊，向後急纵，一名中年道士正\n"+
		"怒视著你，他叫道：「狗贼 !! 纳命来 !!」，又一剑向你刺来。\n\n","HIY") ,
			this_object() );
                set( "alt_corpse", Mob"master_doshu" );
	}
                ::die();
}
