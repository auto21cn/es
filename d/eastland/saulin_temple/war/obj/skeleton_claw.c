#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "skeleton claws", "白骨爪" );
        add( "id", ({ "claw", "claws" }) );
        set_short( "白骨爪" );
        set_long(
                "这是一双泛著白色光芒的爪子，泛著丝丝的寒气。\n"
        );
        set( "unit", "双" );
        set( "nosecond", 1 );
        setup_weapon( "unarmed", 29, 18, 23 );
        set( "bleeding", 15 );
        set( "weight", 140 );
        set( "value", ({ 970, "silver" }) );
        set_c_verbs( ({ "用%s往%s一抓", "%s划出一道青白色的闪光，扫过%s",
                "的%s「嘶」的一声，往%s划去" }) );
}
