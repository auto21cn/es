#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "goose", "白鹅" );
	set_short( "白鹅" );
	set_long(
		"这只鹅正以一种优雅的姿势漫步著。\n"
	);
	set("unit", "只" );
	set("alignment", 200);
	set_c_limbs( ({ "脚丫", "头部", "身体", "翅膀" }) );
	set_c_verbs( ({ "%s张开翅膀往%s拍打", "%s用它的嘴巴啄%s" }) );
	set("plural",1);
}
