#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
        ::create();
	set("lvlimit",15);
	set_level(10);
	set_name( "dragon fly", "蜻蜓" );
        add ("id", ({ "dragon","fly" }) );
        set_short( "蜻蜓" );
	set_long(@C_LONG
一只正在觅食的昆虫。
C_LONG
	);
        set("alignment",-50);
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 10 );
	set( "unit", "只" );
        set_natural_armor(10,4);
	set_natural_weapon( 15,10,18 );
	set_c_verbs( ({ "%s用翅膀拍向%s","%s用嘴咬向%s" }) );
	set_c_limbs( ({ "头部", "胸部", "尾部" }) );
}
