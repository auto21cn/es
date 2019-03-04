#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sword", "长剑" );
	set_short( "征服者之剑" );
	set_long(@CLONG
这是耶拉曼王室家传的宝剑，也就是数百年前耶拉曼大帝征服整个诺顿
大陆时所使用的佩剑。你可以看到剑柄上刻著象徵耶拉曼王室的狮鹫兽
图纹，剑刃上的寒气使你几乎开始发抖。
CLONG
       	        );
	set( "unit", "把" );
	set( "weapon_class", 44 );
	set( "type", "longblade" );
	set( "min_damage", 27 );
	set( "max_damage", 50 );
	set( "nosecond", 1 );
	set( "weight", 180 );
	set( "value", ({ 7000, "gold" }) );
	set( "no_sale", 1 );
}
