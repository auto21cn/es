#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2, ob3, ob4;

	::create();
	set_level(16);
	set_name( "Moorth Knight", "默尔斯骑士" );
	add( "id", ({ "knight" }) );
	set_short( "默尔斯骑士" );
	set_long(
		"你看到一个默尔斯的骑士，他正在寻找敌人——并且企图建立战功\。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_natural_weapon(10,10,10);
	set_natural_armor(30,30);
	    set( "special_defense", ([ "all": 20,"none":10 ]) );
    set("aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":15, "ganglion":15 ]));

	set( "wealth/silver", 250 );
	set( "killer", 1 );
// set( "war_value", 50 );
   set( "war_value", 100 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 90 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默尔斯骑士大叫: 天佑吾皇！荣耀归我默尔斯！\n",
		"默尔斯骑士说道: 丢下武器，不要做无谓的抵抗！\n",
		"默尔斯骑士说道: 你们这些野蛮人，快向默尔斯帝国投降！\n"
	}) );

	ob1 = new( "/d/moorth/obj/bastardsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/moorth/obj/platemail" );
	ob2->move( this_object() );
	equip_armor(ob2);

	ob3 = new( "/d/moorth/obj/helmet" );
	ob3->move( this_object() );
	equip_armor(ob3);

	ob4 = new( "/d/moorth/obj/gauntlets" );
	ob4->move( this_object() );
	equip_armor(ob4);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默尔斯骑士挺身保护" + who->query("c_name") + "。\n",
		this_object() );
}
