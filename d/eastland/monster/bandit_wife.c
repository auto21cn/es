#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name( "bandit's wife", "土匪的妻子" );
	add( "id", ({ "wife" }) );
	set_short( "土匪的妻子" );
	set_long(@C_LONG
你看到一位美丽的少妇，她的装束看起来像是有钱人家的小姐，不过
她的眉目之间却带著几分□悍神色。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "female" );
	set( "alignment", -400 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 16 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 50 );
	set_skill( "dodge", 70 );
	set( "wealth/gold", 75 );
	set( "special_defense", (["all": 25 ]) );
	set_natural_weapon( 4, 4, 4 );
	set_natural_armor( 40, 10 );

	wield_weapon( "/d/eastland/obj/thin_blade" );
}

int stop_attack()
{
	object husband, *tmp;

	husband = present( "bandit", environment() );
	if( !husband ) return 0;
	tell_room( environment(),
		"土匪挺身上前，喝道: 臭小子，敢欺负我老婆？看刀！\n");
	tmp = query_temp( "protectors" );
	if( !tmp || member_array( husband, tmp )==-1 ) {
		add_temp( "protectors", ({ husband }) );
		husband->add_temp( "protectees", ({ this_object() }) );
	}
	tmp = husband->query_attackers();
	if( !tmp || member_array( this_player(), tmp )==-1 )
		husband->kill_ob( this_player() );
}
