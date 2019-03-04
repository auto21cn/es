#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black kernel", "黑核" );
	add( "id", ({ "kernel" }) ); 
   set_short( "黑核" );
	set_long(
		"这是一个颜色黝黑，形状像苹果核的奇怪物品，拿在手上感觉温温的。\n"
	);
	set( "type", "kernel" );
	set( "material", "stone");
	set( "weight", 40 );
	set( "defense_bonus", 4 );
	set( "extra_skills", (["depoison":30]) );
	set( "value", ({ 820, "silver" }) );
}
