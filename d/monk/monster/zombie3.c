
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(3);
	set_name("8-claw zombie", "八爪僵□");
	add( "id", ({ "zombie","8-claw" }) );
	set_short("A 8-claw zombie", "八爪僵□");
	set_long(@C_LONG
八爪僵□是被超渡失败的坏人,因怨恨无法消灭而变成的疆□...
它上辈子是千年蜘蛛精投胎的，最喜欢用八个爪子抓住别人...
它要找一个替身,才能脱离可怕的地狱... 它正轻轻的对著你喷气呢!!!
C_LONG	);
	set( "unit", "只" );
	set( "race", "undead" );
	set( "alignment", -400 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 2, 4 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "dex", 2 );
	set_perm_stat( "karma", 1 );
	set_perm_stat( "str", 3 );
	set_skill("dodge",15);
        set("defense_type","berserk");
	set( "pursuing", 1 );
	set( "tactic_func", "block" );
	set_c_limbs( ({ "半截头颅", "乌黑的身子", "满是蛆的腿", "快断掉的耳朵" }) );
	set_c_verbs( ({ "%s伸出尖尖的爪子，抓向%s","%s伸长枯\骨做的手臂，抓向%s", "%s大声的笑著说『老秃驴受死吧!』，双爪劈向%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1"); 
        set("c_death_msg","八爪僵□被你杀死後化成一滩血水... \n"); 


}

int block()
{
	object victim;
        int i;
        
	if( random(20)>5 || (!i) || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim,
"\n\n八爪僵□突然露出丑陋的奸笑，哇!!! 它身後出现了另外六只手臂 \n\n");
	tell_room( environment(), 
sprintf("\n八爪僵□突然背上长出了另外六只手，一起抓向%s的脖子！\n",victim->query("c_name")),
		({ victim, this_object() }) );
  	for(i=0;i<6;i++)
            this_object()->continue_attack();	
	return 1;
}
