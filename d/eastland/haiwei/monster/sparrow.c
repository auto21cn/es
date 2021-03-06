#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "sparrow", "麻雀" );
	set_short( "麻雀" );
	set_long(
		"你看到一只小小的麻雀在地上跳跃著，似乎不怕生人接近。\n"
	);
	set_perm_stat( "dex", 4 );

	set( "unit", "只" );
	set( "natural_weapon_class1", 2 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 2 );
	set( "alignment", -100 );
	set_c_verbs( ({ "%s往下俯冲，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	set_c_limbs( ({ "头部", "身体", "翅膀" }) );
#include <replace_mob.h>
}
