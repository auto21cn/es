
#include <mudlib.h>
inherit WEAPON;

void create()
{
#include <compress_obj.h>
        set_name( "golden dagger","镶金扁钻" );
        add( "id",({ "dagger","daggercheck" }) );
        set_short( "镶金扁钻" );
        set_long(@C_LONG
这是钱形次郎专用的扁钻，听说钱形次郎每杀一个人，就会在扁钻上镶朵
金色的樱花，现在扁钻的握柄已经镶满金色的花朵，实在太血腥了。       
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 39);
        set( "type", "dagger" );
        set( "min_damage", 27 );
        set( "max_damage", 35 );
        set( "weight", 40 );
        set( "value", ({ 150, "gold" }) );
        set( "second" , 0 );
}

