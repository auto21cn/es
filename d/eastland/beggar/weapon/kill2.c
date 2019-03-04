#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("God Longsword","绝仙剑");
	add ("id",({ "longsword","sword","god" }) );
        set_short("绝仙剑");
	set_long(@C_LONG
绝仙剑乃为通天教主所摆设诛仙阵里的四口宝剑之一。此剑倒悬门上, 发雷□动,
剑光一晃,任从他是万劫神仙,也难逃得此难。 昔曾有赞,赞此宝剑:「非铜非铁又
非钢,曾在须弥山下藏。 不用阴阳颠倒炼,岂无水火淬锋芒? 诛仙利,戮仙亡,陷仙
到处起红光;绝仙变化无穷妙,大罗神仙血染裳。」
C_LONG
	);
	set( "unit", "口" );
        setup_weapon("longblade", 35,28,42);
	set( "weight", 150 );
	set( "no_sale", 1);
        set( "second", 1);
	set( "value", ({ 3410, "silver" }) );
        set("hit_func","my_damage");
}
