#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "mantis", "螳螂" );
	add( "id",({"mantis"}) );
	set_short( "螳螂" );
	set_long(@C_LONG
一只看起来很凶狠的昆虫,晃著两支长长的镰刀虎视眈眈地看著你,似乎要把你吞下
腹。
C_LONG
        );
        set( "unit", "只" );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
        set("weight",650);
	set_skill( "dodge", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "alignment", -200 );
	set_natural_armor( 25, 10 );
	set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
	set_c_verbs( ({ "%s用两支长长的镰刀攻向%s",
                        "%s用嘴狠狠地咬向%s"      
                    }) );
}
