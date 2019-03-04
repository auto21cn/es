//#pragma save_binary

// This is a race body for Undead, Created by Annihilator,
// Updated by Kyoko.
// Beacuse It will be inherited with USER so
// Please don't define any Global variables here.
// This race is used only for NPC now.

#include <daemons.h>
#include <conditions.h>

void setup_race_body()
{
	object body;

	body = this_object();
	body->set("race", "undead");

	// Undead has many any special defense, but afraid of fire and divine.
	body->set("special_defense", ([ "fire": -100, "cold": 70, "acid": 100,
		"poison": 100, "mental": 100, "electric": 70, "energy": 70,
		"magic": 70, "evil": 100, "divine": -100, ]) );

	// This variable effects the critical medication resistance.
//	if( userp(body) ) body->set("constitution", 30);

	// the natural age of Undead.
//	if( userp(body) ) body->set("natural_gae", 0);

	// Apply the heal_up conditions.
	if( body->query("max_hp") ) HEAL_HP->apply_effect(body, 10,  2);
	if( body->query("max_sp") ) HEAL_SP->apply_effect(body, 10,  3);
//	if( body->query("max_tp") ) HEAL_TP->apply_effect(body, 30, 10);
//	if( userp(body) ) HEAL_BODY->apply_effect(body, 30, 7);

	// These variables are used for /adm/daemons/combat_d.c
	body->set_c_verbs( ({ "%s��׼%sһ��ֱȭ", "%s����%sһ��",
		"%s��ȭ����%s", "%s����ץ��%s", }) );
	body->set_c_limbs( ({ "ͷ��", "��۹�", "�ұ۹�", "�߹�", "���ȹ�",
		"���ȹ�", }) );

	// The default tactic function for undead.
	if( !userp(body) ) body->set("tactic_func", "life_drain");
}

int life_drain()
{
	object me, victim;

	if( random(20) > 3 ) return 0;
	me = this_object();
	if( !victim=(object)me->query_attacker() ) return 0;
	if( !present(victim, environment(me)) ) return 0;
	tell_object(victim, 
		sprintf(set_color("\n%s��ȡ���������!!\n\n", "HIR", victim),
			me->query("c_name")));
	tell_room(environment(me), 
		sprintf("\n%s��ȡ%s��������!!\n\n", me->query("c_name"),
			victim->query("c_name")) , ({ me, victim }) );
	victim->receive_special_damage("evil", (int)me->query_level()*2);
	me->receive_healing((int)me->query_level()*2);
	return 1;
}

// These functions are used for race Undead.
// Please don't cover the functions in user.c.
// These are not used because this race is used only for NPC.
/*
int query_natural_life() { return 100; }

// define the cost of advance stats for Undead.
int query_stat_exp_cost(string stat, int val)
{
	mapping stat_exp_rate = ([
		"str": 100, "int": 100, "dex": 100,
		"con": 100, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat)>3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return ((int)STATS_D->query_stat_exp(val) * stat_exp_rate[stat] / 100);
}

int query_stat_exp_rate(string stat)
{
	mapping stat_exp_rate = ([
		"str": 100, "int": 100, "dex": 100,
		"con": 100, "pie": 100, "kar": 100,
	]);

	if( !stat ) return 0;
	if( strlen(stat) > 3 ) stat = stat[0..2];
	if( undefinedp(stat_exp_rate[stat]) ) return 0;
	return stat_exp_rate[stat];
}

// The block_wield() and block_wear() is to check wheather if the player
// can wield a weapon or wear an armor. If the player is not allowed to
// equip the weapon or armor, return 1 to stop.
int block_wield(object obj)
{
	return 0;
}

int block_wear(object obj)
{
	string *allow_types = ({ "body", "head", "arms", "hands", "legs",
		"feet", "shield", "cloak", "misc","finger" });

	if( member_array((string)obj->query("type"), allow_types) == -1 )
		return 1;
	else return 0;
}
*/
