
#include <mudlib.h>
inherit WEAPON;

void create()
{
#include <compress_obj.h>
        set_name("longsword", "长剑");
        add ("id",({ "sword" }) );
        set_short( "长剑" );
        set_long(
            "这是一般的精灵所使用的长剑。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 9 );
        set( "type", "longblade" );
        set( "min_damage", 5);
        set( "max_damage", 8 );
        set( "weight", 70 );
        set( "value", ({ 120, "silver" }) );
}

