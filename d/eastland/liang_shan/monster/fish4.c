#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("common carp", "鲤鱼");
	add("id",({"fish","carp"}) );
	set_short("鲤鱼");
	set_long(
		"这是一条褐黄色的鲤鱼，有须两对，是东方大陆人主要的淡水食用\n"
		"鱼，相当的美味。\n"
	);
	set( "likefish",1);
	set( "unit", "条" );
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 7 );
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}

