#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "yellow cat", "大黄猫" );
	add( "id", ({ "cat" }) );
	set_short( "大黄猫" );
	set_long(
		"一只全身黄毛的大猫，它看起来很凶，像是一只小狮子。\n"
	);
	set_c_limbs( ({ "後腿", "前脚", "头部", "尾巴", "身体" }) );
	set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
	set_skill( "dodge", 10 );
}
