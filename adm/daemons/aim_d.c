//#pragma save_binary
// aim_d.c
// By Annihilator@Eastern.Stories (1-23-94)
// updated by Kyoko@Eastern.Stories (4-17-94)
#include <mudlib.h>
#include <conditions.h>

inherit DAEMON;

mapping diffs = ([
	"ganglion" : 40,
	"weakest" : 55,
	"vascular" : 60,
	"critical" : 105,
]);

// This functuon is called as tactic function from execute_attack() as
// an interface to perform special hit of players.
int aim_target(object me, object victim)
{
	int skill, diffculty;
	string loc;
	object weapon;
	// difficulty for player
	if( random(100) < 30 && !me->query("npc") ) return 0;

	skill = (int)me->query_skill("anatomlogy");
	loc = (string)me->query("aiming_loc");
	if( !skill || !loc ) return 0;

	diffculty = diffs[loc];
	if( undefinedp(diffculty) ) return 0;
	diffculty += diffculty*(int)victim->query("aim_difficulty/"+loc)/100;
	weapon = me->query("weapon1");
	if( weapon ) switch( weapon->query("type") ) {
		case "longblade" : 	skill *= 8;			break;
		case "shortblade" : skill *= 10;		break;
		case "unarmed" : skill *= 9;				break;
		case "dagger" : 	skill *= 11;		break;
		case "blunt" : 		skill *= 9;			break;
		case "axe" : 		skill *= 0;			break;
		case "thrusting" : 	skill *= 13;		break;
		case "polearm" : 	skill *= 1;			break;
		case "chain" : 		skill *= 0;			break;
		case "whip" : 		skill *= 10;		break;
		default:			skill *= 0;
	} else skill *= 9;
	skill /= 10;
	skill += (int)me->query_stat("int") * 2 + (int)me->query_stat("kar");
	skill -= (int)victim->query_stat("int") * 2 + (int)victim->query_stat("kar");
	if( random(skill) < diffculty ) return 0;
	return (int)call_other( this_object(), "hit_" + loc, me, victim );
}

int hit_weakest( object me, object victim )
{
	int damage;

	tell_object(me, set_color( 
		sprintf("你找到了% s的弱点，并且抓住机会攻击！\n",victim->query("c_name"))
	    , "HIY")
	);
	tell_object(victim, set_color ( 
		sprintf("不妙！ %s似乎发现了你防御力最薄弱的部位！\n",me->query("c_name"))
	    , "HIY")
	);
	tell_room( environment(me), 
		sprintf("%s找到了%s的弱点，并且抓住机会攻击！\n",me->query("c_name"),victim->query("c_name")),
		({ me, victim }) );
	damage = me->query("max_damage1");
	victim->receive_damage(damage);
	return damage;
}

int hit_critical( object me, object victim )
{
	int hp, max_hp, damage;

	tell_object(me, set_color(
		sprintf("\n好机会！你发现了%s的致命弱点！\n\n",victim->query("c_name") )
	    ,"HIW")
	);
	tell_object(victim, set_color( 
		sprintf("\n糟糕！%s似乎发现了你的致命弱点！\n\n", me->query("c_name"))
	    ,"HIW")
	);
	tell_room( environment(me), 
		sprintf("\n  %s找到了%s的致命弱点！\n\n",me->query("c_name"),victim->query("c_name")),
		({ me, victim }) );
	hp = victim->query("hit_points");
	max_hp = victim->query("max_hp");
	damage = me->query("max_damage1");
	if( damage < (hp-max_hp/3) ) damage = hp - max_hp/3;
	victim->receive_damage(damage);
	return damage;
}

int hit_vascular( object me, object victim )
{
	int my_int;

	tell_object(me, set_color( 
		sprintf("\n你找到%s血管聚集的地方，并且抓住机会攻击！\n\n", victim->query("c_name") )
	    ,"HIR")
	);
	tell_object(victim, set_color( 
		sprintf("%s用锐利的眼神盯著你瞧，似乎在观察你的弱点 ....　\n",me->query("c_name") )
	    ,"HIR")
	);
	tell_room( environment(me), 
		sprintf("%s用锐利的眼神盯著%s的行动，似乎在观察对手的弱点 ....　\n" ,
		me->query("c_name") ,victim->query("c_name") ),
		({ me, victim }) );
	my_int = (int)(me->query_stat("int"));
	BLEEDING->apply_effect( victim, my_int / 3, my_int / 2 );
	return 0;
}

int hit_ganglion( object me, object victim )
{
	int my_int, vic_con;
	my_int = me->query_stat("int");
	vic_con = victim->query_stat("con");
	if( my_int > (vic_con + 1) ) {

	tell_object(me, set_color ( 
		sprintf("\n你找到%s神经聚集的地方，并且抓住机会攻击！\n\n",victim->query("c_name") )
	    ,"HIC")
	);	
	tell_object(victim, set_color( 
		sprintf("%s用锐利的眼神盯著你瞧，似乎在观察你的弱点 ....　\n",me->query("c_name") )
	    ,"HIC")
	);
	tell_room( environment(me), 
		sprintf("%s用锐利的眼神盯著%s的行动，似乎在观察对手的弱点 ....　\n" ,
		me->query("c_name") ,victim->query("c_name")),
		({ me, victim }) );

		victim->block_attack( (my_int-vic_con)/2 );
		victim->set_temp("msg_stop_attack", 
			"( 你觉得刚才被打中的地方疼痛难当，失去一次攻击机会　 )\n" );
	}
	return 0;
}

