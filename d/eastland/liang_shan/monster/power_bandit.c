#include "../takeda.h"
inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	int i;
	i = random(2);
	::create();
	set_level(10);
	set_name( "mountain thief", "加强型山贼" );
	add( "id", ({ "thief", "bandit" }) );
	set_short( "加强型山贼" );
	set_long(
		"这个山贼一比起别的山贼，多了那麽一点点英武之气，看来不太好惹。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 15 );
	set_skill( "unarmed", 60 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	set( "hit_points", 230 );
	set( "max_hp", 230 );
	set( "wealth/gold", 18 );
	set( "special_defense", (["all": 13 ]) );
	set_natural_weapon( 7, 7, 7 );
	set_natural_armor( 20, 35 );
	wield_weapon( TWEAPON"tiger_finger" );
	equip_armor( TARMOR"vest");
	set( "tactic_func", "my_tactic" );

}
int my_tactic()
{
	int my_dex,my_str,my_kar,num;
	object victim;

	if( random(50)>2 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object(victim,set_color( "说时迟，那时快，一个加强型山贼从阵势中冲了出来向你"
        "施展他的必杀技：十字锁喉反扣。\n","HIM",victim));
	tell_room(environment(this_object()),set_color("说时迟，那时快，一个加强型山贼从阵势中冲了出来向"
	+victim->query("c_name")+"施展他的必杀技：十字锁喉反扣。\n","HIM",victim),victim);
	my_dex = victim->query_stat("dex");
	my_kar = victim->query_stat("kar");
	my_str = victim->query_stat("str");
	num = (my_dex + my_kar + my_str)/5;
	if( random(num) > 3 ) {
	tell_object(victim,set_color( "你侧身闪过加强型山贼的攻击，顺势往他屁屁踢去。\n","HIY",victim));
	tell_room(environment(this_object()),set_color(victim->query("c_name")+
	"侧身闪过加强型山贼的攻击，顺势往他屁屁踢去。\n","HIY",victim),victim);     
	if( random(10) < 5 ) {
	command("moan");
	return 1;
	}        
	tell_object(victim,set_color("不料加强型山贼又一个转身，抓住你的大脚往上一抬，你摔倒在地不能动弹...\n","HIG",victim));
	tell_room(environment(this_object()),set_color("加强型山贼又一个转身，抓住"+victim->query("c_name")+
	"的大脚往上一抬，使他摔倒在地不能动弹...\n","HIG",victim),victim);
	victim->block_attack(2);
	victim->set_temp("msg_stop_attack", "\n（ 你现在摔倒在地无法动弹 ）\n\n ");
	victim->receive_damage(5);
	return 1;
	}
	victim->block_attack(3);
	tell_room(environment(this_object()),set_color(
	    "加强型山贼说道:「好机会，弟兄们快上....」，所有的山贼一涌而上...\n","HIG",victim));
	victim->set_temp("msg_stop_attack", "\n（ 你现在被加强型山贼扣住，动弹不得，无法攻击 ）\n\n");
	victim->receive_damage(10);
	return 1;
}

void die()
{
    object *tmp,leader;
 //   leader = present("leader"); 
    leader = query("master");
	if ( !leader ) {
    ::die();
	return;
    }
    tmp = leader->query_temp("party_members");
    tmp -= ({ this_object() });
    leader->set_temp("party_members",tmp);
    leader->set_temp("embattle_busy",0);
    leader->add("party_num",-1);
    tell_room(environment(this_object()),
    "加强型山贼说道:「怎麽那麽强? 你们先撑一下，我再去叫人....」\n");
    command("wave");
    command("drop all");
    ::die(1);
 }
