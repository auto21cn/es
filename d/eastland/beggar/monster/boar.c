#include "../dony.h"

inherit DMONSTER"limit"; 

void create()
{
        ::create();
	set_level(6);
	set_name( "fat boar", "野猪" );
        add ("id", ({ "boar","fat" }) );
        set_short( "野猪" );
	set_long(@C_LONG
这头野猪实在很胖,胖到你几乎把它误认为别人饲养的猪。\n"
C_LONG
	);
        set("lvlimit",10);
        set("alignment",-50);
	set_perm_stat( "str", 5 );
	set_perm_stat( "dex", 2 );
        set( "race", "beast" );
	set( "unit", "头" );
        set_natural_armor(2,2);
	set_natural_weapon( 9,5,8 );
	set_c_verbs( ({ "%s低头猛冲，撞向%s", "%s在地上一滚，用牙齿往%s顶去" }) );
	set_c_limbs( ({ "头部", "身体", "腿部", "屁股" }) );
}
