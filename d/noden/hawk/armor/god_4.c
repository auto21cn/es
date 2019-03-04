#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Hades Veil","黑帝斯面纱" );
        add( "id", ({ "veil","hades veil" }) );
        set_short( "黑帝斯面纱" );
        set_long(
                "这只黑色的面纱上面画满了许多邪恶的图样, 看来像是冥界黑"+
                "帝斯所用的。\n"
        );
        set( "unit", "只" );
	set("material","cloth");
	set( "type", "head" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 7000, "silver" }) );
}
