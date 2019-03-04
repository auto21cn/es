#include "../ekravia.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "barkeeper", "酒保" );
	add( "id", ({ "barkeeper" }) );
	set_short( "酒保" );
	set_long(@LONG
他擦洗著杯子, 等著下个顾客来点酒, 偶而与前面的顾客低声交谈。
酒吧的酒保总是附近消息最灵通的人。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 50 );
	set( "no_attack", 1);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"酒保默默地擦洗著杯子。\n",
		"一个前面的客人向酒保要了杯酒, 酒保点了点头, 开始调起酒来。\n",
	}) );
	
	set( "inquiry", ([
		"rumor" :	
		"最近没什麽消息, 只听说最近枫树大街上有奇怪的幽灵(phantom)出没。",
		"phantom" :	
		"这我不是很清楚, 不过酒鬼沙理斯宣称他曾经看过。哼, 谁会相信一个酒\n"
		"鬼的醉言醉语呢?",
	]) );
}
