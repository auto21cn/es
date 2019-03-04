
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("black-claw zombie", "乌爪僵□");
	add( "id", ({ "zombie","black-claw" }) );
   set_short( "乌爪僵□" );
	set_long(
"乌爪僵□是被超渡失败的坏人,因怨恨无法消灭而变成的疆□...\n"
"它是从极端的愤恨中产生的怨灵，最喜欢用黑黑的爪子抓住别人...\n"
"它要找一个替身,才能脱离可怕的地狱... 它正轻轻的对著你喷气呢!!!\n"
	);
	set( "unit", "只" );
	set( "alignment", -1000 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 1, 2 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "str", 3 );
	set_skill("dodge",15);
   set( "killer", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "block" );
	set_c_limbs( ({ "半截头颅", "乌黑的身子", "满是蛆的腿", "快断掉的耳朵" }) );
	set_c_verbs( ({ "%s伸出污黑的爪子，抓向%s","%s伸长舌头舔向%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1.c"); 
        set("c_death_msg","僵□被你杀死後化成一滩血水... \n"); 


}

int block()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim, 
"乌爪僵□突然伸长它的手臂，紧紧的掐住你的脖子说著.... 『还...我..命...来!』 \n\n");
	tell_room( environment(), 
"僵□黑爪暴伸 ，牢牢的掐住了" + victim->query("c_cap_name") + "的脖子！\n",
		({ victim, this_object() }) );
	victim->block_attack(4+random(4));
	victim->set_temp("msg_stop_attack", 
"( 你的脖子被掐住,连气都喘不过来了! )\n" );
	return 1;
}
