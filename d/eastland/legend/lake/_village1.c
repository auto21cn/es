// File: /d/eastland/legend/lake/village1.c
// Generated by Roommaker Tue Jun 11 20:05:32 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("古木小径");
	ob->set_long( @LONG_DESCRIPTION
你来到了一条古木小径，小径的两旁有一排排不知名的树木，树枝挡住了阳光
，显得有些阴凉，树上一些鸟儿正啾啾地叫著。你西方有一面大湖，湖上波潭相映
，一波波的涟漪，一只只的白鹭丝或飞或停，煞是情趣。在西南边是湖边的沼泽地
带。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "c_item_desc", ([ 
		"lake" : "一面绿色的大湖。\n" ]) );
	ob->set( "exit_suppress", ({ 
		"southwest", 
		"west" }) );
	ob->set( "exits", ([ 
		"southwest" : "/d/eastland/legend/lake/swamp0", 
		"east" : "/d/eastland/legend/lake/village2", 
		"west" : "/d/eastland/legend/lake/lake7" ]) );
	ob->reset();
}
