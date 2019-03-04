// File: /d/noden/tomb/tomb7.c
// Generated by Roommaker Mon Dec  4 19:34:27 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("墓穴");
	ob->set_long( @LONG_DESCRIPTION
你现在来到一个布满蜘蛛网的通道，厚厚的灰尘与一股令人窒息的尸臭味
令你不由得捏住了鼻子，两边的墙上画满了描述战争的壁画(painting)，但是
由於年代过於久远，已经剥落了大半。
LONG_DESCRIPTION
	);

	ob->set( "c_item_desc", ([ 
		"mark" : "这个符号和洞口的蜘蛛符号一模一样。\n", 
		"painting" : @LONG_TEXT
这些壁画都饧描述一场激烈的战争，另一边是许多紫色皮肤的人匍匐在一个
半人半蝎的怪物面前，那只怪物的胸前有一个蜘蛛符号(mark)。
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"east" : "/d/noden/tomb/tomb8", 
		"west" : "/d/noden/tomb/tomb2" ]) );
	ob->reset();
}
