#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silver_dragon vest", "银龙战甲" );
	add( "id", ({ "vest", "plate" }) );
	set_short( "银龙战甲" );
	set_long(@LONG
诸保昆委托东方大陆名铸造师段铁帮忙冶□他在苗疆所得到的一块玄铁矿，段铁用
这块玄铁矿炼制了数样防御力非凡的护具，最後将剩馀的玄铁制成一片片的鳞片，
嵌入段铁的一件家传银龙甲胄之中，而制成的战甲，有超凡入圣的防御力，不过非
常沈重。
LONG	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 35 );
	set( "defense_bonus", 1 );
	set( "weight", 270 );
	set( "value", ({ 2500, "silver" }) );
}
