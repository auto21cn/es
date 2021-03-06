#include <mudlib.h>
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(19);
	set_name("yamor", "亚默");
	add ("id", ({ "elder", "adventurer" }) );
   	set_short( "亚默长老");
	set_long(
		"亚默长老是一个看起来很慈祥的老人，他年青的时候曾经游历过世界上所\n"
		"有的地方。现在他退休了，住在这里将自己的经验分享给那些和他一样出\n"
		"外冒险的年青人，如果你需要帮助(help)的话，尽管问他。\n" 
	);
	set_perm_stat("strength", 25);
	set_perm_stat("dexterity", 25);
	set_skill( "blunt", 100 );
	set_skill( "dodge", 80 );
	set( "max_hp", 560 );
	set( "hit_points", 560 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1200 );
	set_natural_armor( 120, 35 );
	set_natural_weapon( 25, 13, 30 );
	set("special_defense", ([ "all":40, "none":20 ]) );
	set("aim_difficulty",
			([ "vascular":25, "ganglion":30 ]) );
	set( "tactic_func", "my_tactic" );

	set( "inquiry", ([
		"help" : "@@help_me"
	]) );
	wield_weapon("/d/adventurer/hall/weapons/wiser_staff");
	equip_armor("/d/adventurer/hall/armors/wiser_amulet");
}

void help_me( object who )
{
	tell_room( environment(),
		"亚默长老微笑著说道: 如果你需要帮助的话，去诺达尼亚跟戴利佛提我的名字。\n",
		this_object()
	);
}

int my_tactic()
{
	object *atk;

	if( !(atk = query_attackers()) || random(20)<16) return 0;
	tell_room( environment(this_object()), 
		"亚默长老召唤全能者的神力，你看到他的身边出现一团光雾....然後消失。\n",
		this_object() );
	this_object()->receive_healing(100);
	return 1;
}
