#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name("occult eye", "青灵之眼");
	add("id",({"eye","beholder"}));
	set_short("青灵之眼");
	set_long(
	    "神秘的种族，眼魔，缓缓的从你眼前飞过。\n"
	);
	set( "unit", "只" );
	set_perm_stat("int",30);
	set_natural_weapon( 55, 23, 27 );
	set_natural_armor( 60, 1 );
	set("max_hp",500);
        set("hit_points",500);
	set( "tactic_func", "magic_attack" );
	set("special_defense",(["all":100, "none":50]) );
	set_c_limbs( ({ "头部", "眼睛" }) );
	set_c_verbs( ({ "%s用它的眼睛瞪著%s","%s射出一道光束扫向%s" }) );
        equip_armor(LARMOR"globe1");
}

int magic_attack()
{
	object victim;

	if( !(victim=query_attacker()) || random(10)<4 ) return 0;
	tell_room( environment(this_object()), 
    sprintf("青灵之眼用著它的眼睛发出一道闪亮的白光，直向%s射去。\n",
    victim->query("c_name")));
	victim->receive_special_damage("magic",30+random(20));	
	return 1;
}
