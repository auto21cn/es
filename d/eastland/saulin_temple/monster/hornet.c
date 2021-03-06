

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(2);
        set_name("bee", "野蜂");
        set_short("野蜂");
        set_long(
                "你看到一只嗡嗡叫的野蜂，它正绕著花儿打转，你最好不要惹它。\n"
        );
        set( "unit", "只" );
        set( "alignment", -100 );
	set( "tactic_func", "sting" );
        set_natural_weapon( 5, 2, 5 );
        set_natural_armor( 10, 4 );
        set( "c_death_msg", "%s无力地落到地上，死翘翘了 ....\n" );
        set_c_limbs( ({ "头部", "身体", "翅膀" }) );
        set_c_verbs( ({ "%s发出嗡嗡的叫声，往%s叮去" }) );
}

int sting()
{
        object victim;

        if( random(20)>4 || !(victim= query_attacker()) ) return 0;
        tell_object( victim, 
                "野蜂飞到你的脸上，你感到脸上一阵刺痛！\n");
        tell_room( environment(this_object()), 
                "野蜂飞到" + victim->query("c_name") + "的脸上，用尾针往下一螫！\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 3 );
        return 1;
}
