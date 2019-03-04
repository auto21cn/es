#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "girl", "小女孩" );
	set_short( "小女孩" );
	set_long(@C_LONG
这是渔村里土生土长的小女孩，她正在一旁看其他的小孩子在玩，一快乐的样子。
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
        set_perm_stat( "str", 6 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(35,1);
        set_natural_weapon( 10,6,8 );
}
