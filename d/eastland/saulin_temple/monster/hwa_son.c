#include <../saulin_temple.h>

inherit MONSTER;

void create()
{
	object obj;

	::create();
	set_level( 10);
	add("id",({"monk","son","hwa"}) );
        set_name( "Hwa son", "华尚" );
	set_short("华尚" );
	set_long(@C_LONG
众生无我,一切随缘... 少林也收了很多各类的非人生物,华尚是个蜥蜴人和尚
他在指力方面,有不错的造诣,而且个性随和 开朗...
C_LONG
	);
	set( "race","lizardman"); 
        set( "gender", "male" );
	set( "alignment",  300 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "kar", 12 );
	set_skill( "dodge", 50 );
	set_skill( "unarmed", 80 );
	set( "tactic_func", "my_tactic" );
	set_natural_weapon(19, 10, 20);
	set_natural_armor(50, 18);
        equip_armor(SAULIN_OBJ"silk_tail");

}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim,
		    "华尚尾巴一甩,双手合十.... 使出『穿云指』点了你的穴道！\n\n");
	tell_room( environment(), 
		  sprintf("华尚突然运气一指，点住了%s的穴道！\n", victim->query("c_name")),
		({ victim, this_object() }) );
	victim->block_attack(6);
	victim->set_temp("msg_stop_attack", 
			 "( 你的穴道被点,一时之间无法动弹...... )\n" );
	return 1;
}
