#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "visitor", "观光客" );
	set_short( "观光客" );
	set_long(
		"他是一个初到本镇的观光客，正在对著新奇的事物指指点点。\n"
	);
        set ("gender", "male");
        set ("race", "human");
        set("unit","个");
        set_natural_armor( 28, 10 );
        set_natural_weapon( 6, 5, 13 );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 12 );
	set_skill( "dodge", 60 );
	set( "chat_chance", 15 );
	set( "att_chat_output", ({
		"观光客哭著道：「强盗先生，我什麽都给你 !! 不要杀我 !!」。\n",
	}) );
        set ("wealth", ([ "silver": 50 ]) );
        equip_armor( Obj"glasses" );
}
