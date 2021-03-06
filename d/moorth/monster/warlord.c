#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2, ob3, ob4, ob5, ob6;

	::create();
	set_level(19);
	set_name( "Moorth Warlord", "默尔斯指挥官" );
	add( "id", ({ "warlord" }) );
	set_short( "默尔斯指挥官" );
	set_long(
		"你看到默尔斯军队的指挥官，他正在设法占领诺顿王国的任一个城镇，以便\n"
		"建立军事据点。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set_natural_armor(50,30);
	set_natural_weapon(15,12,15);
	set( "wealth/silver", 400 );
	set( "hit_points", 650 );
	set( "max_hp", 650 );
	set( "special_defense", ([ "all": 40,"none":20 ]) );
	set( "aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":30, "ganglion":15 ]));
        	     
	set( "pursuing", 1 );
	set( "killer", 1 );
// set( "war_value", 100 );
   set( "war_value", 200 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "defend", 100 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默尔斯指挥官冷笑道: 凡是敢阻挡我默尔斯军团者，格杀勿论！\n",
		"默尔斯指挥官说道: 就凭你这点能耐，也敢在我面前撒野？\n",
		"默尔斯指挥官说道: 默尔斯的大军马上就会突破结界，你们的军队是绝对挡不住的！\n"
	}) );

	wield_weapon("/d/moorth/obj/moraz_blade");
	equip_armor("/d/moorth/obj/cape");
	equip_armor("/d/moorth/obj/shield");
	equip_armor("/d/moorth/obj/platemail");
	equip_armor("/d/moorth/obj/helmet");
	ob6 = new( "/d/moorth/obj/gauntlets" );
	equip_armor("/d/moorth/obj/gauntlets");
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("warlord") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({ this_object() }) );
		add_temp( "protectees", ({ who }) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默尔斯指挥官挺身保护" + who->query("c_name") + "。\n",
		this_object() );
}
