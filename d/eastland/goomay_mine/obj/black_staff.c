
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( " balck staff", "黑山神杖");
        add ("id",({ "staff" }) );
        set_short("a black staff", "黑山神杖");
        set_long(@AA
这是段铁为酒境守卫所打造的武器，虽然它并不锋利而且没有魔法的特殊攻击
但由於是掺有些许魔法磁铁矿的精华，加以淬□而成的武器，故坚硬异常是不
错的攻击武器．
AA
);
        set( "weapon_class", 30 );
        set( "min_damage", 15);
        set( "unit","把");
        set( "max_damage", 26);
        set( "type", "blunt");
        set( "weight", 130 );
        set( "value", ({ 400, "silver" }) );
        }