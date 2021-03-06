#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name( "king-kong-po-lo lun", "金刚波罗法轮");
    add( "id", ({ "shield","lun" }) );
    set_short("金刚波罗法轮");
    set_long(@C_LONG
法轮是一种佛法的具相,具有防御及攻击双重的效能... 
金刚波罗法轮是少林几代传下的法器,平时可当做盾牌使
用,防御力超强。
C_LONG
	);
    set( "unit", "座"); 
    set( "type", "shield" );
    set( "armor_class", 10 );
	set("material","monk");
    set( "defense_bonus", 6 );
    set( "weight", 110 );
    set( "value", ({ 150, "gold" }) );
    set( "no_sale", 1 );
}
