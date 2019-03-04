#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "widow serpent", "寡妇蛇" );
	add( "id", ({ "serpent" }) );
	set_short( "寡妇蛇" );
	set_long(@CLONG
这是一种女人的脸，蟒蛇的身体，十分凶暴残忍的一种怪物，她的叫声
像女人哭泣的声音，但是那并不表示她在伤心，而是表示她肚子饿了！
CLONG
	);
	set( "unit", "条" );
	set( "gender", "female" );
	set( "alignment", -1000 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 16 );
	set( "natural_max_damage1", 33 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "dodge", 80 );

	set( "killer", 1 );
	set_c_limbs( ({ "头部", "身体", "尾巴" }) );
	set_c_verbs( ({ "%s张开血盆大口，往%s咬去", "%s摆\动尾巴，甩往%s" }) );
}
