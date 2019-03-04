#include <../tower.h>
void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("恶魔塔内");
	ob->set_long( @C_LONG_DESCRIPTION
这里是恶魔塔的第一个房间.
C_LONG_DESCRIPTION
	);
	ob->set( "exits", ([ 
		"south" : TOWER_F1"tower_gate", 
		"north" : TOWER_F1"room2",
	]) );

	ob->set("objects",([
		"orc" : MOB"orc",
		]) );

	ob->reset();
}
