#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("rainbow cloth","七彩云衣");
        add("id",({"cloth"}) );
        set_short("七彩云衣");
	set_long(@C_LONG
这是用布做的衣服,上面七种颜色交辉相映,煞是好看。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 32 );
	set( "defense_bonus", 6 );
	set( "value", ({ 1500, "silver" }) );
}
