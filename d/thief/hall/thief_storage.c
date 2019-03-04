#include <mudlib.h>
inherit ROOM;

init()
{
	add_action("do_drop","drop");
}
do_drop(string str)
{
	int tmp1,tmp2;
	string stmp1,stmp2;
	if ( ! wizardp(this_player()) ) return 0; 	// 测试时用
#if 0
	if ( !str ) return 0;
	if( sscanf(str, "%d %s %s", tmp1, stmp1, stmp2) == 3 ||
        	sscanf(str, "%d %s", tmp1, stmp1) == 2) return 0;
	if ( str == "all" )
		return notify_fail("请一样一样放.\n");
#endif
	
}

void create()
{
	::create();
	set_short( "小偷公会储藏室");
	set_long(	@C_LONG_DESCRIPTION
这里是小偷公会的储藏室。几年前一些有钱的小偷捐了些钱盖了这座储藏室,
高等级的小偷把一些多馀的装备留在这里, 提供需要的人取用。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : "/d/thief/hall/thief_shop" ]) );
}

int clean_up() { return 0; }
