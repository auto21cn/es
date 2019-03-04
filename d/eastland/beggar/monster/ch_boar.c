#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
	set_level(14);
	set_name( "fat boar", "野猪" );
        add ("id", ({ "boar","fat" }) );
        set_short( "野猪" );
	set_long(@C_LONG
这是一头凶猛的野猪。
C_LONG
	);
        set_perm_stat( "str", 22 );
        set_perm_stat( "dex", 16 );
        set_perm_stat( "kar", 20 );
        set("weight",650);
        set_skill( "dodge", 80 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "alignment", -200 );
        set_natural_armor(25,10);
        set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
        set( "race", "beast" );
	set( "unit", "头" );
	set_c_verbs( ({ "%s低头猛冲，撞向%s", "%s在地上一滚，用牙齿往%s顶去" }) );
	set_c_limbs( ({ "头部", "身体", "腿部", "屁股" }) );
}
void die()
{
    set("alt_corpse",DITEM"bone");
    set( "c_death_msg","%s被打死了,留下一根骨头....\n\n");
    ::die();
}