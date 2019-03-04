#include <races.h>
inherit RACE_HUMAN;

void create()
{
        ::create();
        set_level(15);
        set_name( "holy guard","圣地守卫" );
        add ("id", ({ "guard" }) );
        set_short( "圣地守卫");
        set("unit","位");
        set("alignment",400);
        set("wealth/gold",50);
        set_long(
"你看到一位圣地守卫，神态庄严肃穆地守卫著这儿。\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",25);
        set_perm_stat("str",25);
        set_natural_weapon( 45, 15, 30 );
        set_natural_armor( 72, 20 );
        set ("gender", "male");
        set("special_defense",(["all":10,"none":10]));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
	equip_armor("/d/eastland/tomb/armors/helmet1");
}
