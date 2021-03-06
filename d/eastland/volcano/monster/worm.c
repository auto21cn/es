#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("carrion creeper", "食□虫");
	add( "id", ({ "creeper" }) );
	set_short( "食□虫");
	set_long(
	  "你看到一只食□虫，正蠕蠕而动，它专门吃腐烂的□体，是大自然的清道夫。\n"
	);
	set( "unit", "只" );
	set( "alignment", 50 );
	set( "tactic_func", "wormattack" );
        set_natural_weapon(2,4,5);
	set_c_limbs( ({ "头部", "身体" }) );
	set_c_verbs( ({ "%s张开大口向%s咬去" }) );
}

int sting()
{
	object victim;

	if( random(20)>7 || !(victim= query_attacker()) ) return 0;
	tell_object( victim, 
		"食□虫的嘴里吐出一股恶臭，你闻了差一点没有晕过去！\n");
	tell_room( environment(this_object()),
		"食□虫往"+victim->query("c_cap_name")+"吐出一股恶臭\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 5 );
	return 1;
}
