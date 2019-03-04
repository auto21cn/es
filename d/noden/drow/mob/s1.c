#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name("snake", "小草蛇" );
        set_short("snake", "小草蛇" );
        set_long(
@C_LONG
这是条小草蛇，从你的常识来判别，你知道这是无毒的
C_LONG
        );
        set( "unit", "条" );
        set( "alignment", -200 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set("chat_chance",5);
        set( "chat_output", ({
                "小草蛇在你的脚边游走。\n" }) );
        set_c_limbs( ({ "头部", "身体", "尾巴" }) );
        set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
}

