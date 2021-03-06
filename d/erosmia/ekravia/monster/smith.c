#include "../ekravia.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "smith", "铁匠" );
	add( "id", ({ "smith" }) );
	set_short( "铁匠" );
	set_long(@LONG
一个身材魁武的大汉, 穿著短袖上衣, 满身大汗地在鼓风炉旁工作著。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 100 );
	set( "wealth/silver", 300 );
	set( "no_attack", 1 );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"铁匠使劲地把空气送进炉子里, 一时间炉火大盛, 整个房间都热了起来。\n",
		"铁匠由炉中取出烧红的铁水, 将其倒进模子里成形。\n",
		"铁匠用特别的槌子一槌一槌地敲打炙热的刀身, 将多馀的杂质打出来。\n",
	}) );
}
