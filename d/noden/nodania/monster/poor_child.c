#include "../nodania.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("poorman child", "穷人孩子");
	add( "id", ({ "child" }) );
	set_short("穷人孩子");
	set_long(
		"这个小孩子满身脏污，一双大眼睛正贪婪地望著你的口袋。\n"
	);
	set_skill( "dodge", 10 );
	set( "alignment", 150 );
	set( "wealth/silver", 1 );

	set( "gender", "male" );
	set( "race", "halfling" );
}
