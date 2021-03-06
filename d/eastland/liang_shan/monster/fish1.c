#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("sweetfish", "香鱼");
	add("id",({"fish"}) );
	set_short("香鱼");
	set_long(
		"这是一条美丽的鱼，鳞片细小，口裂广而深，下颚前端截平，缘有锯\n"
		"齿，形状似铲以便於刮食岩石上的藻类为食。\n"
	);
	set("likefish",1);
	set( "unit", "条" );
	set( "alignment", 300 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 3 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 6 );
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}

