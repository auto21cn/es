#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("silver dragon boots", "银龙靴");
        add( "id", ({ "boots", "boot" }) );
        set_short("银龙靴");
        set_long(@C_LONG
龙在中国乃祥瑞之兆, 银龙靴相传是天神赐给东方皇帝的天子之鞋, 
後由朝廷送给少林而後不幸遗失... 现在看起来又破又旧的。
C_LONG
        );
        set("unit", "双");
        set("type", "feet" );
        set("armor_class", 8 );
        set("material","monk");
        set("defense_bonus", 3 );
        set("weight", 30 );
        set("value", ({ 2600, "silver" }) );
}
