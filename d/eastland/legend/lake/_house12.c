// File: /d/eastland/legend/lake/house12.c
// Generated by Roommaker Thu Mar 21 17:26:33 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("矮房子");
	ob->set_long( @LONG_DESCRIPTION
这里是渔村村长的住处；你一进门就看见八张椅子围绕著中间的大桌子，椅子
大小不等，桌上还有些纸张，看来，这是开会的场所。在墙上供奉的是一张仕女图
；图上人物：身材苗窕，体态丰满，双眉间隐隐威严貌，顾盼间颇有勾魂夺魄之态
，这对一个平时打渔为生的村落是不寻常点。在墙角边还有几支渔篓子和几根钓杆
。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"out" : "/d/eastland/legend/lake/village12" ]) );
	ob->set( "objects", ([ 
		"captain" : "/d/eastland/legend/monster/captain1" ]) );
	ob->reset();
}
