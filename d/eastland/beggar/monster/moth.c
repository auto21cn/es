#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
        ::create();
	set_level(9);
	set_name( "grey moth", "小灰蛾" );
        add ("id", ({ "moth","grey" }) );
        set_short( "小灰蛾" );
	set_long(@C_LONG
一只飞不起来的小灰蛾。
C_LONG
	);
        set("lvlimit",15);
        set("alignment",-50);
	set_perm_stat( "str", 8 );
	set_perm_stat( "dex", 8 );
	set( "unit", "只" );
        set_natural_armor(8,4);
	set_natural_weapon( 13,8,15 );
	set_c_verbs( ({ "%s用翅膀拍向%s","%s用翅膀拍击%s" }) );
	set_c_limbs( ({ "头部", "胸部", "触角" }) );
}
	