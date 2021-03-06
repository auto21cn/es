#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(6);
	set_name( "mini horse", "迷你马" );
	add( "id", ({ "horse" }) );
	set_short( "迷你马" );
	set_long(
		"这是一匹可爱的迷你马，如果你想练习骑术的话，可以试著骑(mount)它。\n" );
	set( "unit", "匹" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 2 );
	set_natural_armor( 25, 12 );
	set_natural_weapon( 8, 4, 10 );
	set( "c_extra_look", "$N正骑著一匹可爱的小迷你马。\n");
	set( "alignment", 100 );
	set( "mountable", 1);
	set( "max_load", 1600 );
	set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
	set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起来，用前肢在%s一阵上乱蹬" }) );
}

void init()
{
//	monster::init();
	mount::init();
	
}
