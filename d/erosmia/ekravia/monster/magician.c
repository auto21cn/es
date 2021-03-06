#include "../ekravia.h"

inherit MONSTER;

void create()
{
	object	hat, coat, pants;

	::create();
	set_level(9);
	set_name( "wounder magician", "魔术师" );
	add( "id", ({ "magician" }) );
	set_short( "流浪魔术师" );
	set_long(@LONG
专门带给众人欢笑的魔术师。他的身材普通, 身穿一套黑色的燕尾服, 头
上戴著注册商标般的黑色高帽子。灵巧的手配合著略显夸张的表情, 流畅
地演出著令人叹为观止的魔术。
LONG
	);
	set_perm_stat( "str", 7 );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 7 );
	set_perm_stat( "pie", 10 );
	set_natural_weapon( 20, 9, 19 );
	set_natural_armor( 25, 9);
	set( "gender", "male" );
	set( "alignment", 200 );
	set( "wealth/silver", 100 );
	
	hat = clone_object( OBJ"black_hat" );
	coat = clone_object( OBJ"coat" );
	pants = clone_object( OBJ"pants" );
	hat->move(this_object());
	coat->move(this_object());
	pants->move(this_object());
	equip_armor(hat);
	equip_armor(coat);
	equip_armor(pants);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"魔术师摘下帽子, 向在场所有观众鞠了个恭。\n",
		"突然间, 两只鸽子从帽子里飞了出来, 又飞进帽子, 又飞出来, 但飞出来"
		"的却是八只。\n",
		"魔术师倒倒帽子, 示意里面空空如也。\n",
		"魔术师右手轻轻一挥, 一个气球飞了出来, 飘向广阔的天空。\n",
		"魔术师两手一扬, 地上爆起一阵烟雾, 在烟雾散去後只见那顶高帽子倒放"
		"在地, 人消失了。\n",
		"一大堆的鸽子毫无预警地由帽子里飞出, 带著一堆彩带, 後面跟著魔术师"
		"本人\n－从帽子里爬了出来。\n",
		"众人给予魔术师热烈的掌声, 纷纷把钱丢进他的高帽子里。\n"
	}) );
}
