#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("snake-fish", "七星鳢");
	add("id",({"fish","snake"}) );
	set_short("七星鳢");
	set_long(
		"这是一条造型奇特的鱼，学名是七星鳢，但一般人都叫它姑呆，\n"
		"看起来笨笨呆呆，好像一块大木头漂在水里，事实上，它是一种凶猛\n"
		"的掠食性鱼类。\n"
	);
	set( "likefish",1);
	set( "killer",1);
	set( "pursuing",1);
	set( "unit", "条" );
	set( "alignment", -200 );
	set_skill("swimming",100);
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 14 );
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}

