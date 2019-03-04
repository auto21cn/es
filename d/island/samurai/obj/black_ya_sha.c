
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Blacksword＿Ya＿Sha", "黑夜叉" );
        add( "id",({ "sword" }) );
        set_short( "Blacksword＿Ya＿Sha", "黑夜叉" );
        set_long("this is a black blade.\n",
            " 这是一把剑身乌黑，剑长且薄的利剑，这也是武士副队长星＿卡的爱剑\n"
        );
        set( "unit", "把");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 40 );
        set( "nosecond",0);
        set( "weight", 170 );
        set( "value", ({ 150, "gold" }) );
}


