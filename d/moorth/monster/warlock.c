#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(19);
	set_name( "Moorth Warlock", "Ĭ��˹ս��" );
	add( "id", ({ "warlock" }) );
	set_short( "Ĭ��˹ս��" );
	set_long(
		"�㿴��һ��Ĭ��˹�ġ�ս�ס������������������˹Ů�ʵ������ӣ�����\n"
		"ʩ�����������ħ��ʦ���߳��Ľ����������˲���������\��\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1500 );
   set( "hit_points", 550 );
   set( "max_hp", 550 );
	set( "special_defense", ([ "all": 70,"none":20 ]) );
   set( "aim_difficulty", ([ "weakest" : 40, "vascular" : 40 ]) );
   set( "natural_armor_class", 50 );
	set( "natural_defense_bonus", 30 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 10 );
   set( "natural_min_damage2", 10 );
   set( "natural_max_damage2", 15 );
	set( "wealth/gold", 400 );
	set( "wimpy", 150 );
	set( "killer", 1 );
	set( "tactic_func", "my_tactic" );
// set( "war_value", 250 );
   set( "war_value", 500 );
	set_perm_stat( "str", 26 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 26 );
	set_skill( "shortblade", 100 );
	set_skill( "wand", 100 );
   set_skill( "two-weapon", 100 );
	set_skill( "dodge", 100 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"Ĭ��˹ս�״��: ������Щ�޴���֪��ŵ���ˣ�ͨͨ�����µ���ȥ�ɣ�\n",
		"Ĭ��˹ս��˵��: ɱ��������Щ������ֱ�����˷��ҵ�ʱ�䣡\n",
		"Ĭ��˹ս��˵��: ŵ���������������������˹֮�ڽ�������\n"
	}) );

	ob1 = new( "/d/moorth/obj/wand" );
	ob1->move( this_object() );
	wield_weapon(ob1);
   wield_weapon2( "/d/moorth/obj/electrum_sword" );

	ob2 = new( "/d/moorth/obj/robe" );
	ob2->move( this_object() );
	equip_armor(ob2);
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim= query_attackers()) ) return 0;
	if( random(20)<4 ) {
	  for( i=0; i<sizeof(victim); i++ ) {
		message( "tell_object",
			"Ĭ��˹ս�׿������: Del-Ka'ta Mu-ju'ra .....\n"
			"ͻȻ��һ���̹ǵĺ������������׶���˹��������ŵ�һ��Ѫ�ȵ���ζ��\n",
			victim[i],
			this_object() );
	  }
		victim->receive_special_damage("magic", 70);
		return 1;
	} else return 0;
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("magician") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"Ĭ��˹ս��ͦ������"+who->query("c_name")+"��\n",
		this_object() );
}