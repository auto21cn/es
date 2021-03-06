#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name("snake", "百步蛇" );
        set_short("百步蛇" );
        set_long(
@C_LONG
这是一尾美丽的蛇，不停的吐信并且冷冷的看著四周，你知道这是
条拥有剧毒的蛇类，还是别碰它好！
C_LONG
        );
        set( "unit", "条" );
        set( "alignment", -700 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "头部", "身体", "尾巴" }) );
        set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
}

int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "百步蛇张开嘴巴向你咬下，你觉得全身传来一阵剧痛！！！\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
29, 3 );
        return 1;
}       
