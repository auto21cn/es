#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman Marshal Knight","战事指挥官" );
	add( "id", ({ "lizardman","marshal","knight" }) );
	set_short( "蜥蜴人战事指挥官" );
	set_long(@LONG
    你看到的是一位好战的骑士，它等待这一刻已经不知道等多久，
兴奋的它正大开杀戒以示庆祝，你最好别靠近它以免成为它的猎物。
LONG
		);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-1150 );
	set_natural_weapon( 37,11,22 );
	set_natural_armor( 68,30 );
	set( "max_hp",500 );
	set( "hit_points",750 );
	set( "special_defense",
	([ "fire":50,"cold":50,"energy":40,"electric":40,"none":50 ]) );
	set( "aim_difficulty",
	([ "critical":90,"vascular":45,"weakest":60,"ganglion":100 ]));
	set( "stun_difficulty",90 ); 
	set( "wealth/silver",890 );
	set( "tactic","melee" );
	set( "killer",1 );
	set( "justice",50 );
	set( "pursuing",1 );
	set_perm_stat( "str",27 );
	set_perm_stat( "dex",24 );
	set_skill( "polearm",100 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
	set( "chat_chance",10 );
	set( "att_chat_output",({
	"\n蜥蜴人指挥官冷冷地说：从来没有人能从我的手中逃生的，乖乖地受死吧！\n\n",
	"\n蜥蜴人指挥官不屑地说：以你的能力想胜过我，再回家练十年吧！\n\n" }) );
	set( "tactic_func","my_tactic" );
	wield_weapon( IWARO"polearm" );
	equip_armor( IWARO"shield4" );
	equip_armor( IWARO"helmet3" );
	equip_armor( IWARO"arms4" );
	equip_armor( IWARO"amulet2" );
	equip_armor( IWARO"plate6" );
}

int my_tactic()
{
	string him;
	object victim;
	
	victim=query_attacker();
	him=victim->query( "c_name" );
	if( !victim || victim->query( "conditions/bleeding" ) ) return 0;
	if ( random(99) >14 ) return 0;
	tell_object( victim,
	"\n蜥蜴人指挥官突然飞快地向你胸膛刺出一枪，你发现你胸口\n"+
	"上多了一个碗大的窟窿，鲜血如喷泉般不断地冒出来！\n\n" );
	tell_room( environment( victim ),
	"\n蜥蜴人指挥官突然飞快地向"+him+"的胸膛刺出一枪，你发现\n"
	+him+"的胸口多了一个碗大的窟窿，鲜血如喷泉般不断冒出来！\n\n",victim );	
	victim->set( "conditions/bleeding",({ 2,15,4 }) );
	return 1;
}
