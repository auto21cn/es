#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silver claw", "银爪" );
	add( "id", ({ "claw", "cybilas" }) );
   set_short( "赛比拉斯银爪" );
	set_long(
		"这副银爪就是传说中古赛比拉斯人的武器，你可以看到银爪上镶著一颗\n"
		"赛比拉斯红宝石，旁边围绕著七颗完美的珍珠。\n"
	);
	set( "unit", "副" );
	set( "type", "unarmed" );
	set( "weapon_class", 36 );
	set( "min_damage", 14 );
	set( "max_damage", 28 );
	set( "second", 1 );
	set( "weight", 70 );
	set( "value", ({ 540, "silver" }) );
	set( "bleeding", 15 );

	set_c_verbs( ({ "用%s往%s一抓", "%s划出一道漂亮的银光，扫过%s",
		"的%s发出「嗤」的一声，往%s划去" }) );
}
