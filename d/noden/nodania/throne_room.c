#include "nodania.h"

inherit ROOM;

void create()
{
	object king;

	::create();
	set( "light", 1 );
	set_short( "议事厅" );
	set_long(@CLONG
你来到了国王耶拉曼十一世的议事厅，国王平常都在这里和大臣们
商讨国事，议事厅的布置和大厅差不多，国王的王座旁边有两张比较小
的座椅，分别是皇后和小公主的座位。南边是王宫的大厅，东边的回廊
通往国王的图书馆，西边则是皇后的收藏室。
CLONG
	);
	set( "exits", ([
		"south" : NODANIA"palace_hall",
		"west" : NODANIA"collection",
		"east" : NODANIA"e_throne"
	]) );
	set( "objects", ([
		"body guard#1" : NODANIA"monster/body_guard",
		"body guard#2" : NODANIA"monster/body_guard",
	]) );
	king = new(NODANIA"monster/yaramon_xi");
	king->move(this_object());

	reset();
}

int clean_up() { return 0; }
