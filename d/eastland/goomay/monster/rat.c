#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "rat", "老鼠" );
	set_short( "a rat", "老鼠" );
	set_long(
		"A small rat. It looks pretty hungry.\n",
		"一只瘦小的老鼠，看起来好像饿了很久。\n"
	);
	set_perm_stat("dex", 3 );
	set_perm_stat("str", 2 );

	set_c_verbs( ({ "%s用爪子乱抓%s", "%s张嘴往%s咬下" }) );
	set_c_limbs( ({ "头部", "身体", "前爪", "後腿", "尾巴" }) );

	set( "unit", "只" );
	set( "natural_armor_class", 8 );
#include <replace_mob.h>
}
