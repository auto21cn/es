#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("God-killed Shortsword","诛仙剑");
	add ("id",({ "shortsword","sword","god-killed" }) );
        set_short("诛仙剑");
	set_long(@C_LONG
这是由通天教主所摆设的诛仙剑阵里的一把武器,剑身透出一阵阵的蓝光。据说,
姜子牙曾经败在这把诛仙剑之下,可见得这把武器有多麽厉害。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("shortblade", 38,28,42);
	set( "weight", 100 );
	set( "no_sale", 1);
	set( "value", ({ 10, "silver" }) );
}

