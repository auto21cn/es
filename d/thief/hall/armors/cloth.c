#include <mudlib.h>
inherit ARMOR;
void create()
{
	seteuid(getuid());
	set_name("night cloth","夜行服");
	add("id",({"cloth"}));
	set_short("夜行服");
	set_long(@LONG
这是一件轻便的深色衣服, 使小偷在夜间活动时能轻易的隐藏自己。
衣服上有许\多口袋, 可以放小刀, 万能锁, 铁丝等小巧的工具。
LONG
	);
	set("unit","件");
	set("weight",40);
	set("type","body");
	set("material","thief");
	set("armor_class",12);
	set("defense_bonus",3);
        set( "value", ({ 960, "silver"} ) );
	set( "extra_skills",(["hide":2,"sneak":2]) );
}
