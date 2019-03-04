#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "dragon shield", "绝龙牌" );
        add( "id", ({ "shield" }) );
        set_short( "绝龙牌" );
        set_long(@C_LONG
一面有刀剑斫击留下痕迹的盾牌,想必是替主人挡下了不知多少次的攻击。在盾牌
上还有一只张牙舞爪的青龙,甚是凶猛貌,对於敌人或许有些许的恫赫作用。  
C_LONG       
        );
        set("unit","块");
        set( "type", "shield" );
        set( "material", "cloth" );
        set( "armor_class",7 );
        set( "defense_bonus", 1 );
        set( "weight", 100 );
        set( "value", ({ 1360, "silver" }) );
}
