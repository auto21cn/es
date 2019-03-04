#include <mudlib.h>
#include "academy.h"

inherit ROOM;

void create()
{
	::create();
	set( "light", 1);
	set( "max_laod", 100000 );	
	set_short( "The Hall", "入口大厅" );
	set_long( @LONG
It needs work here.	
LONG
, @C_LONG
这里是巫师学院的大厅, 由此可以前往学院中的几个不同的部门。这
里有三个主要的部门, 开始学习的新巫师们可以先前往西边的控制部门,
在那里你可以学到正式的巫师们所拥有的各种力量, 与如何使用这些力量
。进阶的学生们则必须前往东边的语言部门, 学习创造这个世界的语言--
LPC 的文法与规则。最後在北边的实验部门学习如何开始创造物品、生物
、与建造房间等, 并学习如何解决未知的问题。

    在你学完所有的课程之後, 北边的实验部门将会给你一道最後的考验
。通过这道考验, 你就能取得成为正式巫师的必要资格。
C_LONG
	);
	set( "light", 1 );
	set( "exits", ([
		"south"  : HERE"entry",
		"west"	: HERE"command_hall",
		"east"	: HERE"lpc_hall",
		"north" : HERE"work_hall"
	]) );
}
