#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name( "sky lun", "梵天法轮");
        add( "id", ({ "shield", "lun" }) );
        set_short("梵天法轮");
        set_long(@C_LONG
法轮是一种佛法的具相, 具有防御及攻击双重的效能。
不要相信你鉴定的结果, 梵天法轮是非常好又轻的防具。
C_LONG
		);
        set( "unit", "座"); 
        set( "type", "shield" );
        set( "armor_class", 8 );
	set("material","monk");
        set( "defense_bonus", 4 );
        set( "weight", 50 );
        set( "value", ({90, "gold" }) );
}
