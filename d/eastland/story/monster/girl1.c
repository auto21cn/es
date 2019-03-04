#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "wing girl", "羽民小妹妹" );
	add( "id", ({ "girl" }) );
	set_short( "羽民小妹妹" );
	set_long(@C_LONG
一个居住在羽民村里的小孩。她年约十一、二岁，头上绑著一个马尾辫子，一对乌
溜溜的大眼，模样甚是可爱。小女孩正在和她的同伴追逐嬉戏，不时传来欢乐的笑
声。
C_LONG
        );
	set( "gender", "female" );
	set( "alignment", 100 );
        set( "race","羽民" );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
        set( "player_invisible" ,1 );
}
