#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "vagabond","市井流氓" );
	set_short( "市井流氓" );
	set_long(@C_LONG
一个整天无所事事的无赖汉，只会欺负一些良家妇女，所以你最好小心一点，不要
招惹他。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
        set( "killer",1);
        set("alignment",-50);
        set_perm_stat( "str", 10 );
        set_perm_stat( "dex", 10 );
        set( "unit", "个" );
        set_natural_armor(50,1);
        set_natural_weapon( 15,10,18 );
}
