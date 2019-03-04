#include "../takeda.h"

inherit OBJECT;

void create()
{
	set_name( "jail key", "地牢钥匙" );
	add( "id", ({ "key" }) );
	set_short( "a jail key", "地牢钥匙" );
	set_long(
		"This is the key of Liang Shan jail.\n",
		"这是一把青石作成的钥匙，握在手上感到阵阵寒意。\n"
	);
	set( "to_lock", "LiangShankey-1" );
	set( "weight", 3 );
	set( "value", ({ 30, "silver" }) );
	set( "no_sale", 1 );
}
