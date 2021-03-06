#include "../ekravia.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Dino", "迪诺" );
	add( "id", ({ "dino" }) );
	set_short( "旅店老板  迪诺" );
	set_long(@LONG
一个身材高大的中年人, 全身上下散发出一种坚毅与勇敢的气质, 二十年
前的他应该是个极为出色的骑士吧? 不知为何这样的人会在这里默默地经
营一家旅店。
LONG
	);
	set_perm_stat( "str", 27);
	set_perm_stat( "dex", 23 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 25);
	set_perm_stat( "pie", 15 );
	set( "natural_armor_class", 100 );
	set( "natural_defense_bonus", 20 );
	set( "max_hp", 1000 );
	set( "hit_points", 1000 );
	set( "gender", "male" );
	set( "alignment", 800 );
	set( "wealth/silver", 5000 );
	set( "no_attack", 1);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"老板坐在柜台前, 默默地翻阅\著手上的书籍。\n",
		"老板望了你一眼, 沈稳地问道「这位客人, 您是要住一晚吗?」\n",
		"老板拿著抹布, 轻轻地擦拭著柜台旁边的架子。\n"
	}) );
}
